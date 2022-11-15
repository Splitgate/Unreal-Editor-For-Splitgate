// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Globals.h"
#include "PortalWarsBaseGameState.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsBaseGameState : public AGameState
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	TArray<APlayerState*> InactivePlayerArray;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int RemainingTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int ReplicatedRemainingTime;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
	FString PlaylistType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
	EServerType ServerType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
	FGameConfig GameConfig;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
	int MaxPlayers;

	UFUNCTION(BlueprintCallable)
	void OnRepRemainingTime() {};

	UFUNCTION(BlueprintCallable)
	void OnRep_GameConfig() {};

	UFUNCTION(BlueprintPure)
	int GetRemainingTime() { return 0; };
};
