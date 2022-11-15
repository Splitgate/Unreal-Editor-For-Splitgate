// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/Gun.h"
#include "Bat.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API ABat : public AGun
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float BatteryPercentagePerSwing;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UParticleSystem* MeleeImpact1PFX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UParticleSystem* MeleeImpact3PFX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	FLinearColor ElectricityInEffectsRangeColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	FLinearColor ElectricityInMeleeRangeColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	FLinearColor BatInEffectsRangeEmissiveColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	FLinearColor BatInMeleeRangeEmissiveColor;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float EffectsRange;                       
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float MaxOpenPercentInEffectsRange;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float FullyOpenInterpSpeed;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float FullyClosedInterpSpeed;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float EffectsRangeInterpSpeed;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float PlateInterpToVisibleSpeed;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float PlateInterpToHiddenSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UMaterialInstanceDynamic* BatDynamicMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UMaterialInstanceDynamic* ElectricityDynamicMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UMaterialInstanceDynamic* PlatesDynamicMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UMaterialInstanceDynamic* ThirdPersonBatDynamicMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UMaterialInstanceDynamic* ThirdPersonElectricityDynamicMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* BatAmbientStartEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* BatAmbientStopEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* BatOpenedSFX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* OutOfAmmoMeleeHitSound;

};
