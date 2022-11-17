// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "GameModes/PortalWarsBaseGameMode.h"
#include "Globals.h"
#include "PortalWarsGameMode.generated.h"

UCLASS()
class PORTALWARS_API APortalWarsGameMode : public APortalWarsBaseGameMode
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ScoreStep;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MinScore;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxScore;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 KillScore;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 AssistScore;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DeathScore;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 SuicideScore;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 FriendlyFireScore;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 TeabagScore;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DamageSelfScale;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bTeamGame;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	uint8 NumTeams;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 GameModeID;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FGameConfig GameConfig;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int32> CompatibleWeaponIDs;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<class AGun>> DefaultInventoryClasses;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bCanSpawnPickups;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bAllowReplayRecording;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bObjectiveGame;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float _dt;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float _max;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float _min;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float _Kp;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float _Kd;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float _Ki;

	
	UFUNCTION(BlueprintCallable)
	bool IsWinner(class APlayerState* PlayerState) { return false; }; // class APortalWarsPlayerState*
	
	UFUNCTION(BlueprintCallable)
	bool IsTie(class APlayerState* PlayerState) { return false; }; // class APortalWarsPlayerState*
	
	UFUNCTION(BlueprintCallable)
	int32 GetPlacement(class APlayerState* PlayerState) { return 0; }; // class APortalWarsPlayerState*
	
	UFUNCTION(BlueprintCallable)
	void ForceEndMatch() {};
};
