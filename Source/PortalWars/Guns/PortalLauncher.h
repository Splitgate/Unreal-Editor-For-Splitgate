// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/BaseGun.h"
#include "Portals/Portal.h"
#include "PortalLauncher.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalLauncher : public ABaseGun
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	TSubclassOf<APortal> PortalBPClass = APortal::StaticClass();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	APortal* LeftPortal;  

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	APortal* RightPortal;    

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	float PortalLauncherRange;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	float TimeBetweenPortalShots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	float TimeToDestroyPortalAfterDeath;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	FVector TrailFXOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	USceneComponent* AkPortalGun;                                   
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* FirePortalEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* ClosePortalEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* SuccessfulPortalEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* FailPortalEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	UParticleSystem* TrailFX;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	FName TrailTargetParam;

	UFUNCTION(BlueprintNativeEvent)
	void SpawnPortalFX_Multicast(const FVector_NetQuantize& EndPoint);
	
	UFUNCTION(BlueprintCallable)
	void ServerClosePortal(bool bIsLeftPortal) {};

	UFUNCTION(BlueprintCallable)
	void ServerAttemptToSpawnPortal(bool bIsLeftPortal, FVector_NetQuantize& StartTrace, FVector& ShootDir) {};

	UFUNCTION(BlueprintCallable)
	void DelaySpawnPortalFX(const FVector_NetQuantize& EndPoint) {};
};
