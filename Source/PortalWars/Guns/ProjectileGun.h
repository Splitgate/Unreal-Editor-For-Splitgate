// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/Gun.h"
#include "../Projectiles/Projectile.h"
#include "ProjectileGun.generated.h"

USTRUCT(Blueprintable)
struct FProjectileWeaponData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ProjectileLife;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ExplosionDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DamageFalloff;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinimumDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UDamageType> DamageType;
};

/**
 * 
 */
UCLASS()
class PORTALWARS_API AProjectileGun : public AGun
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	FProjectileWeaponData ProjectileConfig;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float LocalHitDetectionDuration;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	bool bSpawnsLocalProjectiles;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	TArray<AProjectile*> LocalProjectiles;

	UFUNCTION(BlueprintCallable)
	void ServerSpawnProjectile(const FVector_NetQuantize& Origin, const FVector_NetQuantizeNormal& Dir, int ProjectileID) {};

	UFUNCTION(BlueprintCallable)
	void ServerHandleExplosionLocal(FHitResult& Impact, int ProjectileID) {};
};
