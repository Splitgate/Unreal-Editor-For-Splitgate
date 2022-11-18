// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Globals.h"
#include "PortalWarsCharacter.generated.h"

USTRUCT(Blueprintable)
struct FIgnoreMovementCorrections
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	uint8                                        bIgnoreServerCorrections : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	uint8                                        ForceRep;
};

UCLASS()
class PORTALWARS_API APortalWarsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	APortalWarsCharacter();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	//class APortalWarsGameState* GameStateRef;                            
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float Health;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float MaxHealth;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float HealthRechargeDelay;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* HealthRechargeStartEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* HealthRechargeStopEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* LowHealthStartEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* LowHealthStopEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* KillHealthLoopEvents;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	FTakeHitInfo LastTakeHitInfo;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	class UAnimMontage* UpperBodyFlinchMontage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	class UAnimMontage* LowerBodyFlinchMontage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	class UAnimMontage* HeadFlinchMontage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	TSubclassOf<class UDamageType> SuicideDamageType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	TSubclassOf<class UDamageType> PortalDamageType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* PlayerTakeDamageEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* RagdollCollisionEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	float RagdollImpactSFXThreshold;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	float PostDeathPortalLifetime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	float RagdollLifetime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	class UCameraComponent* ThirdPersonCamera;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	class USpringArmComponent* ThirdPersonCameraArm;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	class UCameraComponent* SpectatorFirstPersonCamera;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	class USpringArmComponent* SpectatorFirstPersonCameraArm;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	TArray<TSubclassOf<class AGun>> DefaultInventoryClasses;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	TArray<class AGun*> Inventory;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	class AGun* CurrentWeapon;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	class AGun* Fists;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	TSubclassOf<class AGun> FistsClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	TSubclassOf<class AGun> CurrentWeaponClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Settings")
	FName WeaponAttachPoint;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Settings")
	FName GrendadeAttachPoint;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	TSubclassOf<class APortalLauncher> PortalLauncherClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	class APortalLauncher* PortalLauncher;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Settings")
	FName PortalLauncherAttachPoint;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Components")
	class USceneComponent* FirstPersonArmsRoot;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Components")
	class USkeletalMeshComponent* Mesh1P;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Components")
	class USkeletalMeshComponent* HelmetMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Components")
	class USkeletalMeshComponent* UpperMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Components")
	class USkeletalMeshComponent* LowerMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Components")
	class UStaticMeshComponent* JetpackMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Components")
	class UStaticMeshComponent* JetpackFlameMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	int32 FriendlyStencilValue;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	int32 EnemyStencilValue;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	int32 AlphaTeamStencilValue;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	int32 BravoTeamStencilValue;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Team Settings")
	class UMaterialInstance* EnemyCharacterMaterialOverride;            
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Animations")
	class UAnimSequence* EmoteSequenceCurrentlyPlayingInMenu;           
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	bool bIsSprinting;                                
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	TSubclassOf<class UCameraShake> SprintCamShake;  
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float SprintingSpeedModifier;                          
	
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	//class APortalWarsTeabagZone* TeabagZone;               
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float CrouchCameraSpeed;                               
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* CrouchEvent;                                  
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* UncrouchEvent;                                
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float BaseTurnRate;                                    
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float BaseLookUpRate;                                  
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float ControllerMaxAccelMultiplierX;                   
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float ControllerMaxAccelMultiplierY;                   
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float TimeToReachMaxAccelX;                            
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float TimeToReachMaxAccelY;                            
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	class AController* OwnerOfLastPortalUsed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float RotateToUprightSpeed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
	bool DoRep_collisionProfile;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* TeleportEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* LocalPlayerTeleportEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	TSubclassOf<class AProjectile> GrenadeClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	uint8 CurrentGrenades;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	uint8 NumStartingGrenades;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	uint8 MaxGrenades;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* ThrowGrenadeEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
	FIgnoreMovementCorrections IgnoreServerCorrections;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float MeleeApplyDmgRange;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float MeleeApplyDmgRangeXY;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float MeleeApplyDmgAngle;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float MeleeRange;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float TimeBetweenMelee;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float MeleeConeHalfAngle;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float MeleeMaxRotationAngle;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	TSubclassOf<UDamageType> MeleeDamageType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	bool bIsThrusting;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float ThrustAmountPerTick;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float ThrusterVelocityThreshhold;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float ThrusterRechargeDelay;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float ThrusterTotalTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float ThrusterCurrentTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* JetPackStartEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* JetPackEndEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	bool bIsZooming;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Values")
	float MaxTimeOutOfBounds;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	float CurTimeOutOfBounds;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* OutOfBoundsStartEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* OutofBoundsEndEvent;

	//class UPortalWarsAnimInstanceV2* Animation;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* DeathEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* RespawnEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* RespawnCountdownEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* RespawnCountdownStopEvent;
	
	//class UPortalWarsIndicatorWidget* NameIndicatorWidget;
	//class UPortalWarsRadarMarkerWidget* RadarMarkerWidget;
	//class APortalWarsPlayerState* LastPlayerState;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
	int RemotePitch;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
	int RemoteYaw;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
	int RemoteRoll;

	UFUNCTION(BlueprintCallable)
	void UpdateSkins() {};
	
	UFUNCTION(BlueprintCallable)
	void UpdateCollisionProfiles() {};
	
	UFUNCTION(BlueprintCallable)
	void StopEmoteInMenu() {};
	
	UFUNCTION(BlueprintCallable)
	void StopEmote() {};
	
	UFUNCTION(BlueprintCallable)
	void ServerTeleport(const FTransform_NetQuantize& CharacterTransform_world, FVector_NetQuantize& NewVel, FQuat& NewControlRotation) {};
	
	UFUNCTION(BlueprintCallable)
	void ServerStartMelee(class APortalWarsCharacter* InEnemyToMelee) {};
	
	UFUNCTION(BlueprintCallable)
	void ServerSetZooming(bool bNewZooming) {};
	
	UFUNCTION(BlueprintCallable)
	void ServerSetOwnerOfLastPortalUsed(class APortal* LastPortalUsed) {};
	
	UFUNCTION(BlueprintCallable)
	void ServerSetOverlappingPortalCollisionProfiles() {};
	
	UFUNCTION(BlueprintCallable)
	void ServerSetDefaultCollisionProfiles() {};
	
	UFUNCTION(BlueprintCallable)
	void ServerRequestSuicide() {};
	
	UFUNCTION(BlueprintCallable)
	void ServerPlayEmote() {};
	
	UFUNCTION(BlueprintCallable)
	void ServerInterruptEmote() {};
	
	UFUNCTION(BlueprintCallable)
	void ServerHandleTeabagging(TArray<class APortalWarsCharacter*>& DeadBodies) {};
	
	UFUNCTION(BlueprintCallable)
	void ServerFinishMelee(const FVector_NetQuantize100& EndingLocation) {};
	
	UFUNCTION(BlueprintCallable)
	void ServerEquipWeapon(class AGun* NewWeapon) {};
	
	UFUNCTION(BlueprintCallable)
	void ServerAttemptManualPickup(class AActor* GunPickup, const FVector_NetQuantize& CurrentWeaponLocation, const FVector_NetQuantizeNormal& CurrentWeaponRotation) {};
	
	UFUNCTION(BlueprintCallable)
	void ServerApplyMeleeDamage(class APortalWarsCharacter* EnemyToDamage) {};
	
	UFUNCTION(BlueprintCallable)
	void RequestSuicide() {};
	
	UFUNCTION(BlueprintCallable)
	void PlayEmoteInMenu_Internal() {};
	
	UFUNCTION(BlueprintCallable)
	void PlayEmote_Multicast() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_portalGun() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_LastTakeHitInfo() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_IsZooming() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_IsThrusting() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Inventory() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_IgnoreServerCorrections() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Health(float OldHealth) {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_CurTimeOutOfBounds() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_CurrentWeapon(class AGun* LastWeapon) {};

	UFUNCTION(BlueprintNativeEvent)
	void OnReplayCameraModeChanged(EReplayCameraMode NewReplayCameraMode);
	
	UFUNCTION(BlueprintNativeEvent)
	void OnGlobalVisionChanged();

	UFUNCTION(BlueprintNativeEvent)
	void OnDeath();

	UFUNCTION(BlueprintNativeEvent)
	void OnComponentHit(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, const FVector& NormalImpulse, FHitResult& Hit);

	UFUNCTION(BlueprintCallable)
	void MoveAndPostToMoveableAk(UObject* AkEvent, const FVector& NewLocation) {};

	UFUNCTION(BlueprintPure)
	bool IsZooming() { return bIsZooming; };
	
	UFUNCTION(BlueprintPure)
	bool IsSprinting() { return bIsSprinting; };
	
	UFUNCTION(BlueprintPure)
	bool IsRecentlyRendered(float Threshold) { return true; };
	
	UFUNCTION(BlueprintPure)
	bool IsLocallyViewed() { return true; };
	
	UFUNCTION(BlueprintPure)
	bool IsFirstPerson() { return true; };
	
	UFUNCTION(BlueprintPure)
	bool IsFiring() { return true; };
	
	UFUNCTION(BlueprintPure)
	bool IsEnemyFor(class APortalWarsCharacter* Character) { return true; };
	
	UFUNCTION(BlueprintPure)
	bool IsDead() { return false; };
	
	UFUNCTION(BlueprintPure)
	bool IsAlive() { return true; };

	UFUNCTION(BlueprintCallable)
	void InterruptEmote_Multicast() {};

	UFUNCTION(BlueprintPure)
	class AGun* GetWeapon() { return CurrentWeapon; };
	
	UFUNCTION(BlueprintPure)
	float GetSprintingSpeedModifier() { return SprintingSpeedModifier; };
	
	UFUNCTION(BlueprintPure)
	class AGun* GetSecondaryWeapon() { return CurrentWeapon; };
	
	UFUNCTION(BlueprintPure)
	class USkeletalMeshComponent* GetMesh1P() { return Mesh1P; };
	
	UFUNCTION(BlueprintPure)
	class UObject* GetAkComponent(FName AkName) { return nullptr; };

	UFUNCTION(BlueprintPure)
	FRotator GetAimOffsets() { return FRotator(); };

	UFUNCTION(BlueprintCallable)
	void DestroyPortals() {};
	
	UFUNCTION(BlueprintCallable)
	void DelayedServerFinishMelee() {};
	
	UFUNCTION(BlueprintCallable)
	void ClientNotifyAlive(class AController* C) {};
	
	UFUNCTION(BlueprintCallable)
	void ClientFailedPickupAttempt() {};
	
	UFUNCTION(BlueprintCallable)
	void ClientExpelCharacterFromPortal(FTransform_NetQuantize& PortalTransform_world) {};
	
	UFUNCTION(BlueprintCallable)
	void ClientEquipWeapon(class AGun* NewWeapon) {};
	
	UFUNCTION(BlueprintCallable)
	void ClientDropSpecialItem(class ASpecialItem* SpecialItem) {};
	
	UFUNCTION(BlueprintCallable)
	void ApplyShotgunPointImpulsesToCorpseMulticast(TArray<FPWPointDamageEvent>& DamageEvents) {};
	
	UFUNCTION(BlueprintCallable)
	void ApplyPointImpulseToCorpseMulticast(FPWPointDamageEvent& PointDamageEvent) {};
};
