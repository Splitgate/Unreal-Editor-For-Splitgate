// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/BaseGun.h"
#include "Globals.h"
#include "GameFramework/ForceFeedbackEffect.h"
#include "../Components/UI/AmmoCounterWidgetComponent.h"
#include "Gun.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API AGun : public ABaseGun
{
	GENERATED_BODY()
	
public:

	AGun();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	EBodyPart BodyPartTargetForBots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float TimeBetweenShotsForBots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	FWeaponData WeaponConfig;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	TSubclassOf<AActor> PickupClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	uint8 GunValue;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int CurrentAmmo;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int CurrentAmmoInClip;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float EquipTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	bool bAutoEquip = true;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	bool bCanFirePortalsWhileEquipped;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	FRecoilData RecoilConfig;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* MeleeSwingEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* MeleeHitEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	bool IsMeleeWeapon;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	TSubclassOf<UDamageType> MeleeDamageType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float MinTimeBeforeApplyingMeleeDmg;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	float MeleeRangeScaleOverride;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	int GunID;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	FString InternalName;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	FText DisplayName;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	UTexture2D* GunIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	FReticleData ReticleConfig;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Config")
	FAutoAimData AutoAimConfig;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	EWeaponState CurrentState;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	UForceFeedbackEffect* FireForceFeedback;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage EquipAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage FireAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage ReloadAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage ReloadShortAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	TArray<FWeaponAnimMontage> MeleeAnims;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage ThrowGrenadeAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage FirePortalAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage ClosePortalAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimMontage InspectWeaponAnim;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	FWeaponAnimList WeaponSpecificAnimations;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* FireEvent;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* OutOfAmmoEvent;                                   
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* FireStopEvent;                                    

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* ZoomInEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* ZoomOutEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* AmmoPickupEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* GunCollisionEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* EquipEvent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Events")
	UAmmoCounterWidgetComponent* AmmoCounter;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Events")
	UAmmoCounterWidgetComponent* ChargeCounter;

public:

	UFUNCTION(BlueprintCallable)
	void ServerSpawnGrenade(const FVector_NetQuantize& Origin, const FVector_NetQuantizeNormal& Dir);
	
	UFUNCTION(BlueprintCallable)
	void ServerGoToState(EWeaponState NewState);
	
	UFUNCTION(BlueprintCallable)
	void PlayWeaponSound(UObject* Sound);
	
	UFUNCTION(BlueprintCallable)
	void OnRep_CurrentState(EWeaponState PrevState);

	UFUNCTION(BlueprintCallable)
	void OnRep_AmmoInClip();

	UFUNCTION(BlueprintNativeEvent)
	void OnGunImageLoaded();

	UFUNCTION(BlueprintCallable)
	void LoopWeaponSound(bool IsFiring);
	
	UFUNCTION(BlueprintPure)
	bool GetCanZoom() { return true; };
	
	UFUNCTION(BlueprintPure)
	UObject* GetAkComponent() { return nullptr; };
	
	UFUNCTION(BlueprintCallable)
	void ClientStartReload();
};
