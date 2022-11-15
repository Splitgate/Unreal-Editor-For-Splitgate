// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/LineTraceGun.h"
#include "Shotgun.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API AShotgun : public ALineTraceGun
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	int NumPelletsPerShell;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage ReloadStartAnim;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage ReloadInsertAnim;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage ReloadStopAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	TMap<APawn*, FDamageEvents> CharacterHitsMap;

	UFUNCTION(BlueprintCallable)
	void ServerProcessHits(TArray<FLineTraceHitResult>& HitResults, TArray<FLineTraceInfo>& bulletTracesPacked) {};
	
	UFUNCTION(BlueprintCallable)
	void ReloadWeapon_Multicast(bool ShouldInsert) {};
};
