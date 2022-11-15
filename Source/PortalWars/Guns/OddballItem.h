// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/SpecialItem.h"
#include "GameFramework/GameState.h"
#include "OddballItem.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API AOddballItem : public ASpecialItem
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	AGameState* OddballGameState;                          
};
