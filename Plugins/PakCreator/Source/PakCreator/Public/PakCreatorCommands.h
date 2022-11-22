// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "PakCreatorStyle.h"

class FPakCreatorCommands : public TCommands<FPakCreatorCommands>
{
public:

	FPakCreatorCommands()
		: TCommands<FPakCreatorCommands>(TEXT("PakCreator"), NSLOCTEXT("Contexts", "PakCreator", "PakCreator Plugin"), NAME_None, FPakCreatorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};