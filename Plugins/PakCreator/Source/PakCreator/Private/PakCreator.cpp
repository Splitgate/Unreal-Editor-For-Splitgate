// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PakCreator.h"
#include "PakCreatorStyle.h"
#include "PakCreatorCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "HAL/FileManager.h"
#include "HAL/PlatformFileManager.h"
#include "IUATHelperModule.h"
#include "PlatformInfo.h"
#include "EditorStyleSet.h"
#include "FileHelper.h"
#include "Interfaces/IPluginManager.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "InstalledPlatformInfo.h"
#include "PakFileUtilities.h"
#include "IPlatformFilePak.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"

static const FName PakCreatorTabName("Package Mod");

#define LOCTEXT_NAMESPACE "FPakCreatorModule"

void FPakCreatorModule::StartupModule()
{
	FPakCreatorStyle::Initialize();
	FPakCreatorStyle::ReloadTextures();

	FPakCreatorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FPakCreatorCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FPakCreatorModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FPakCreatorModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FPakCreatorModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FPakCreatorModule::ShutdownModule()
{
	FPakCreatorStyle::Shutdown();

	FPakCreatorCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(PakCreatorTabName);
}

const TCHAR* GetUATCompilationFlags()
{
	return (FApp::GetEngineIsPromotedBuild() || FApp::IsEngineInstalled())
		? TEXT("-nocompile -nocompileeditor")
		: TEXT("-nocompileeditor");
}

TArray<FString> AssetPaths;
void UatComplete(FString FinishType, double Time)
{
	struct DirectoryVisitor : public IPlatformFile::FDirectoryVisitor
	{
		bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) override
		{
			if (bIsDirectory)
			{
			}
			else
			{
				AssetPaths.Add(FilenameOrDirectory);
			}
			return true;
		}
	};

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString PluginResPath = IPluginManager::Get().FindPlugin("PakCreator")->GetBaseDir() / TEXT("Resources");
	FString CookedFolder = FPaths::ProjectSavedDir() + "/Cooked/WindowsNoEditor/" + FApp::GetProjectName() + "/Content";
	FString IntPath = FPaths::ProjectIntermediateDir() + "Paks";

	if (FinishType == "Completed")
	{
		DirectoryVisitor Visitor;
		PlatformFile.IterateDirectoryRecursively(*CookedFolder, Visitor);
		FString EntryFile = FPaths::ProjectIntermediateDir() + "/Paks/Entries.txt";

		if (FPaths::FileExists(EntryFile))
			IFileManager::Get().Delete(*EntryFile, true);

		if (FFileHelper::SaveStringToFile("", *EntryFile))
		{
			TArray<FString> ConjuredEntries;

			for (FString File : AssetPaths)
			{
				FString SplitString;
				File.Split("Content/", nullptr, &SplitString);
				FString FixedFile = File.Replace(TEXT("Saved//Cooked"), TEXT("Saved/Cooked"), ESearchCase::IgnoreCase).Replace(TEXT("/"), TEXT("\\"), ESearchCase::IgnoreCase);

				FString FormattedEntry = FString::Printf(TEXT("\"%s\" \"../../../%s/Content/%s\""), *FixedFile, FApp::GetProjectName(), *SplitString);
				ConjuredEntries.Add(FormattedEntry);
			}

			FFileHelper::SaveStringArrayToFile(ConjuredEntries, *EntryFile);

			FString FinalPakCommand = FString::Printf(TEXT("\"%s\" -Create=\"%s\""), *FString(IntPath.Replace(TEXT("/"), TEXT("\\"), ESearchCase::IgnoreCase) + "\\pakchunk30-WindowsClient.pak"), *EntryFile.Replace(TEXT("/"), TEXT("\\"), ESearchCase::IgnoreCase));

			FString PlatPath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*FPaths::EngineDir());

			int32 OutReturnCode;
			FString OutStdOut;
			FString OutStdErr;

			FWindowsPlatformProcess::ExecProcess(
				*FString(FPaths::EngineDir() + "Binaries/Win64/UnrealPak.exe"),
				*FinalPakCommand,
				&OutReturnCode,
				&OutStdOut,
				&OutStdErr
			);

			ConjuredEntries.Reset();
			AssetPaths.Reset();
		}
	}
}

void FPakCreatorModule::PluginButtonClicked()
{
	const PlatformInfo::FPlatformInfo* const PlatformInfo = PlatformInfo::FindPlatformInfo("WindowsNoEditor");
	check(PlatformInfo);

	FString ProjectPath = FPaths::IsProjectFilePathSet() ? FPaths::ConvertRelativePathToFull(FPaths::GetProjectFilePath()) : FPaths::RootDir() / FApp::GetProjectName() / FApp::GetProjectName() + TEXT(".uproject");
	FString CommandLine = FString::Printf(TEXT("BuildCookRun -nocompile -nocompileeditor -installed -nop4 -project=\"%s\" -cook -skipstage -ue4exe=\"%s\" -targetplatform=Win64 -utf8output"),
		*ProjectPath,
		*FUnrealEdMisc::Get().GetExecutableForCommandlets()
	);

	IUATHelperModule::Get().CreateUatTask(CommandLine, PlatformInfo->DisplayName, LOCTEXT("CookingContentTaskName", "Cooking"), LOCTEXT("CookingTaskName", "Cooking"), FEditorStyle::GetBrush(TEXT("MainFrame.CookContent")), UatComplete);
}

void FPakCreatorModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FPakCreatorCommands::Get().OpenPluginWindow);
}

void FPakCreatorModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FPakCreatorCommands::Get().OpenPluginWindow);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPakCreatorModule, PakCreator)