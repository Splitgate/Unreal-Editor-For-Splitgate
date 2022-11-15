// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/PlayerState.h"
#include "Globals.h"
#include "PortalWarsCustomAntiCheat.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API UPortalWarsCustomAntiCheat : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TMap<APlayerState*, FCheatViolations> PlayerViolations;

};
