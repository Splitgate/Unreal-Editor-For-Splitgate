// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/Gun.h"
#include "LineTraceGun.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API ALineTraceGun : public AGun
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	FLineTraceGunData LineTraceGunConfig;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	TSubclassOf<AActor> ImpactTemplate;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	AActor* ImpactManager;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	float MaxImpactEffectDistance;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	float MaxSimulatedImpactEffectDistance;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	TArray<FLineTraceInfo> BulletNotify;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	UParticleSystem* TrailFX;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	FName TrailTargetParam;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	FName ColorParam;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	int TracerFrequency;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* BulletWhizEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	float MaxBulletWhizDist;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	float BulletWhizDelay;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	FVector BulletWhizStart;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	FVector BulletWhizEnd;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Impact / Bullets")
	FVector BulletWhizClosestPoint;

public:

	UFUNCTION(BlueprintCallable)
	void ServerNotifyMiss(TArray<FLineTraceInfo>& bulletTraces) {};
	
	UFUNCTION(BlueprintCallable)
	void ServerNotifyHit(FLineTraceHitResult& LineHit, float ReticleSpread, TArray<FLineTraceInfo>& bulletTraces) {};

	UFUNCTION(BlueprintCallable)
	void PlayBulletWhiz(FVector& StartPoint, FVector& EndPoint) {};

	UFUNCTION(BlueprintCallable)
	void OnRep_BulletNotify() {};

	UFUNCTION(BlueprintPure)
	float GetCurrentSpread() { return 0.0f; };
};
