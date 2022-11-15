// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/LineTraceGun.h"
#include "BurstLineTraceGun.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API ABurstLineTraceGun : public ALineTraceGun
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	FBurstLineTraceGunData BurstLineTraceGunConfig;
};
