// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PortalWarsBaseGameState.h"
#include "Globals.h"
#include "Globals1047.h"

#include "PortalWarsLobbyGameState.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsLobbyGameState : public APortalWarsBaseGameState
{
	GENERATED_BODY()
	
public:
	
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Lobby Settings")
	//FEndGameInfo PrevGameData;          
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Lobby Settings")
	class AStaticMeshActor* TVScreen;          

	UFUNCTION(BlueprintCallable)
	void UpdateTVScreen() {};

	UFUNCTION(BlueprintCallable)
	void OnRep_PrevGameData() {};
};
