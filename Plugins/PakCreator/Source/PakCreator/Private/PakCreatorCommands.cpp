// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PakCreatorCommands.h"

#define LOCTEXT_NAMESPACE "FPakCreatorModule"

void FPakCreatorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "Package Mod", "Produce modded package.", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
