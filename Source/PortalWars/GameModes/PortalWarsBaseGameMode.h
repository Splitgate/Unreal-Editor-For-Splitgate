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

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxPlayers;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxBots;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<class APawn> BotPawnClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UClass* AIControllerClass; // TSubclassOf<class APortalWarsAIController>


	UFUNCTION(BlueprintCallable)
	void CreateBotDelayed() {};
};
