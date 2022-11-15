// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "AmmoCounterWidgetComponent.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API UAmmoCounterWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPortalWarsAmmoCounterWidget* AmmoCounterWidget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TickInterval;
};
