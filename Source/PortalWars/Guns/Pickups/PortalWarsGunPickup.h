// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Guns/Pickups/PortalWarsPickup.h"
#include "PortalWarsGunPickup.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsGunPickup : public APortalWarsPickup
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Weapon Pickup Config")
	TSubclassOf<class AGun> WeaponClass;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Pickup Config")
	uint8 GunValue;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Pickup Config")
	FText GunDisplayName;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Pickup Config")
	UTexture2D* GunImage;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Pickup Config")
	int32 GunID;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Pickup Config")
	int32 TotalAmmo;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Pickup Config")
	float ImpactThreshold;

	UFUNCTION(BlueprintNativeEvent)
	void OnGunImageLoaded();

	UFUNCTION(BlueprintNativeEvent)
	void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, const FVector& NormalImpulse, FHitResult& Hit);
};
