// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/LineTraceGun.h"
#include "MultiKillGun.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API AMultiKillGun : public ALineTraceGun
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void ServerNotifyHits(TArray<FLineTraceHitResult>& LineHits, float ReticleSpread, TArray<FLineTraceInfo>& bulletTraces) {};
};
