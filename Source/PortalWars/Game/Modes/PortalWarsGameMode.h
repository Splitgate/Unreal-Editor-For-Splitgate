// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "PortalWarsBaseGameMode.h"
#include "Globals.h"
#include "PortalWarsGameMode.generated.h"

UCLASS()
class PORTALWARS_API APortalWarsGameMode : public APortalWarsBaseGameMode
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		int32 ScoreStep;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		int32 MinScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		int32 MaxScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		int32 KillScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		int32 AssistScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		int32 DeathScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		int32 SuicideScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		int32 FriendlyFireScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		int32 TeabagScore;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
		float DamageSelfScale;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
		bool bTeamGame;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
		uint8 NumTeams;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
		int32 GameModeID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
		FGameConfig GameConfig;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Config")
		TArray<int32> CompatibleWeaponIDs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Config")
		TArray<TSubclassOf<class AGun>> DefaultInventoryClasses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gun Config")
		bool bCanSpawnPickups;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
		bool bAllowReplayRecording;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
		bool bObjectiveGame;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gobbledygook")
		float _dt;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gobbledygook")
		float _max;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gobbledygook")
		float _min;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gobbledygook")
		float _Kp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gobbledygook")
		float _Kd;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gobbledygook")
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
