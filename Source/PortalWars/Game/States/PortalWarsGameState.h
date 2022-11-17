// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "PortalWarsBaseGameState.h"
#include "../../Misc/PortalWarsCustomAntiCheat.h"
#include "PortalWarsGameState.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsGameState : public APortalWarsBaseGameState
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
	UPortalWarsCustomAntiCheat* AntiCheat;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
	bool bTeamGame;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	TArray<int> TeamScores;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	FString WinningTeamName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	bool bHasPlayerQuit;

	//TArray<class APortalWarsPickup*> Pickups;       
	//TArray<class AOutOfBoundsVolume*> OOBVolumes;   

	UFUNCTION(BlueprintCallable)
	void OnRep_TeamGame() {};

	UFUNCTION(BlueprintCallable)
	void OnRep_Score() {};
	//TArray<class APortalWarsPlayerState*> GetSortedPlayers(int32 TeamNum);

	UFUNCTION(BlueprintPure)
	int GetNumberOfPlayersOnTeam(int TeamNum) { return 0; };
	//bool AreEnemyPlayers(class APortalWarsCharacter* PS1, class APortalWarsCharacter* PS2);
	//bool AreEnemies(class APortalWarsPlayerState* PS1, class APortalWarsPlayerState* PS2);

};
