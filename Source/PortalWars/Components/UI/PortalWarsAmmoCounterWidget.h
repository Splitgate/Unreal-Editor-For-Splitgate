// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PortalWarsAmmoCounterWidget.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API UPortalWarsAmmoCounterWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UTextBlock* AmmoText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UProgressBar* ChargeProgressBar;
};
