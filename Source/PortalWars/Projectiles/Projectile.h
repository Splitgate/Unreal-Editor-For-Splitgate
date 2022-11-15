// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Globals.h"
#include "BaseActors/CullableActor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API AProjectile : public ACullableActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UProjectileMovementComponent* MovementComp;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USphereComponent* CollisionComp;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USphereComponent* PawnCollisionComp;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ProjectileID;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsInitialProjectile;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UObject* AkComp;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UParticleSystemComponent* ParticleComp;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UParticleSystem* ExplosionFX;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UObject* ExplosionEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UObject* ProjectileLoopStartEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UObject* ProjectileLoopStopEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDecalData Decal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool CanTeleport;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bExploded;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bDestroyed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float OverlapSphereGrowthRate;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxPawnOverlapSphereSize;

	UFUNCTION(BlueprintCallable)
	void OnRep_ProjectileID() {};

	UFUNCTION(BlueprintCallable)
	void OnRep_Exploded() {};
	
	UFUNCTION(BlueprintNativeEvent)
	void OnPawnSphereHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, const FVector& NormalImpulse, FHitResult& HitResult);

	UFUNCTION(BlueprintNativeEvent)
	void OnImpact(struct FHitResult& HitResult);
		
	UFUNCTION(BlueprintNativeEvent)
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, const FVector& NormalImpulse, FHitResult& HitResult);

	UFUNCTION(BlueprintCallable)
	void DisableAndDestroy() {};

};
