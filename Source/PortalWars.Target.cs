// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class PortalWarsTarget : TargetRules
{
	public PortalWarsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "OnlineSubsystem1047Utils" } );
		ExtraModuleNames.AddRange( new string[] { "PortalWarsEditor" } );
		ExtraModuleNames.AddRange( new string[] { "PWInMemoryNetworkReplayStreaming" } );
		ExtraModuleNames.AddRange( new string[] { "PWDualNetworkReplayStreaming" } );
		ExtraModuleNames.AddRange( new string[] { "PortalWarsMoviePlayer" } );
		ExtraModuleNames.AddRange( new string[] { "PortalWarsGlobals" } );

		ExtraModuleNames.AddRange( new string[] { "PortalWars" } );
	}
}
