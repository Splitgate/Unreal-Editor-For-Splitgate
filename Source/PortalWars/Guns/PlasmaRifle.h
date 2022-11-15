// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/ProjectileGun.h"
#include "PlasmaRifle.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APlasmaRifle : public AProjectileGun
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	float CurrentHeatLevel;                              
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float HeatIncreasePerShot;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float CoolDownRate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float TotalHeatCapacity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* OverHeatChargeEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* OverHeatChargeStopEvent;

	UFUNCTION(BlueprintCallable)
	void OnRep_CurrentHeatLevel() {};
};
