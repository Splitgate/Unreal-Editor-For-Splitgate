// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "PortalWarsTeamStart.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsTeamStart : public APlayerStart
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	int32 SpawnTeam;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	uint8 bNotForPlayers : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	uint8 bNotForBots : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	uint8 bInitialSpawn : 1;
};
