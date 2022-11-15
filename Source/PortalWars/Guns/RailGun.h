// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/MultiKillGun.h"
#include "RailGun.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API ARailGun : public AMultiKillGun
{
	GENERATED_BODY()
	
public:	

	ARailGun();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage ChargeAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage DischargeAnim;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* ChargeStartEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* ChargeStopEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* DischargeEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UParticleSystem* ChargeFX_1P;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UParticleSystem* ChargeFX_3P;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Weapon Effects")
	UParticleSystemComponent* ChargePSC_1P;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Weapon Effects")
	UParticleSystemComponent* ChargePSC_3P;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float TimeToCharge;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float BatteryPercentagePerShot;
};
