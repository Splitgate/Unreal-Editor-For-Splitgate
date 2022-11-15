// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/ProjectileGun.h"
#include "RocketLauncher.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API ARocketLauncher : public AProjectileGun
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FRocketStateSpecificMontages EquipAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FRocketStateSpecificMontages FireAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	TArray<FWeaponAnimMontage> RocketMeleeEmptyAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	TArray<FWeaponAnimMontage> RocketMeleeFullAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FRocketStateSpecificMontages ThrowGrenadeAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FRocketStateSpecificMontages FirePortalAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FRocketStateSpecificMontages ClosePortalAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FRocketStateSpecificMontages InspectWeaponAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FRocketStateSpecificMontages ReloadStartAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FRocketStateSpecificMontages ReloadInsertAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FRocketStateSpecificMontages ReloadStopAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimList EmptyAnimations;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimList FullAnimations;

	UFUNCTION(BlueprintCallable)
	void ReloadWeapon_Multicast(bool ShouldInsert) {};
};
