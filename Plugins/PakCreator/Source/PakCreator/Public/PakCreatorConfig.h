// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"

#include "PakCreatorConfig.generated.h"

/**
 * 
 */
UCLASS(Config = Modding, defaultconfig, meta = (DisplayName = "Pak Creator"))
class PAKCREATOR_API UPakCreatorConfig : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	FString GamePakPath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*FString(FPaths::ProjectIntermediateDir() + "/Paks"));

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	FString PakChunkName = "pakchunk30-WindowsNoEditor.pak";

	UPROPERTY(BlueprintReadOnly, Config)
	FString INFORMATION = "This stuff is not functional atm.";
};
