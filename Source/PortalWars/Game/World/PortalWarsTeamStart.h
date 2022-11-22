// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "Engine/Texture2D.h"
#include "Components/BillboardComponent.h"

#include "PortalWarsTeamStart.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsTeamStart : public APlayerStart
{
	GENERATED_BODY()
	
public:

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	int32 SpawnTeam;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	uint8 bNotForPlayers : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	uint8 bNotForBots : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	uint8 bInitialSpawn : 1;

	UTexture2D* BlueTeamTexture = (UTexture2D*)StaticLoadObject(UTexture2D::StaticClass(), this, TEXT("/Game/UI/HUD/Indicators/Textures/indicator-pointer-blue.indicator-pointer-blue"));
	UTexture2D* RedTeamTexture = (UTexture2D*)StaticLoadObject(UTexture2D::StaticClass(), this, TEXT("/Game/UI/HUD/Indicators/Textures/indicator-pointer-red.indicator-pointer-red"));
	UTexture2D* AmbientTeamTexture = (UTexture2D*)StaticLoadObject(UTexture2D::StaticClass(), this, TEXT("/Game/UI/HUD/Indicators/Textures/indicator-pointer-white.indicator-pointer-white"));
};
