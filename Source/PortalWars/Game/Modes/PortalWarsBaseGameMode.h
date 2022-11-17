// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PortalWarsBaseGameMode.generated.h"

UCLASS()
class PORTALWARS_API APortalWarsBaseGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
	int32 MaxPlayers;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
	int32 MaxBots;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
	TSubclassOf<class APawn> BotPawnClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game Config")
	UClass* AIControllerClass; // TSubclassOf<class APortalWarsAIController>


	UFUNCTION(BlueprintCallable)
	void CreateBotDelayed() {};
};
