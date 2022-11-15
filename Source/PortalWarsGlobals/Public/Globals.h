// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "Animation/AnimSequence.h"
#include "Animation/BlendSpace1D.h"
#include "GameFramework/DamageType.h"
#include "Globals.generated.h"

// Enums And Structs

UENUM(BlueprintType)
enum class EBodyPart : uint8
{
	Torso = 0,
	Head = 1,
	Feet = 2
};

UENUM(BlueprintType)
enum class ECustomizationType : uint8
{
	None = 0,
	Helmet = 1,
	Chest = 2,
	Legs = 3,
	Jetpack = 4,
	PortalGun = 5,
	AssaultRifle = 6,
	BattleRifle = 7,
	Pistol = 8,
	PlasmaRifle = 9,
	Railgun = 10,
	RocketLauncher = 11,
	Shotgun = 12,
	SMG = 13,
	Sniper = 14,
	PortalInside = 15,
	PortalRing = 16,
	Gender = 17,
	Emblem = 18,
	Emote = 19,
	Oddball = 20,
	Bat = 21,
	NameTag = 22,
	DMR = 23
};

UENUM(BlueprintType)
enum class ECustomizationRarity : uint8
{
	None = 0,
	Common = 1,
	Rare = 2,
	Epic = 3,
	Legendary = 4
};

UENUM(BlueprintType)
enum class EChallengeType : uint8
{
	None = 0,
	Daily = 1,
	Weekly = 2,
	Weapon = 3
};

UENUM(BlueprintType)
enum class ERewardType : uint8
{
	None = 0,
	Customization = 1,
	XP = 2,
	XPBoost = 3,
	DoubleXP = 4,
	Lootbox = 5,
	Currency = 6,
	SecondaryCurrency = 7
};

UENUM(BlueprintType)
enum class EAmmoType : uint8
{
	None = 0,
	Bullet = 1,
	Battery = 2
};

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	NotEquipped = 0,
	UnEquipping = 1,
	Equipping = 2,
	Idle = 3,
	Firing = 4,
	Reloading = 5,
	Meleeing = 6,
	Throwing = 7,
	FiringPortal = 8,
	ClosingPortal = 9,
	Inspecting = 10
};

USTRUCT(Blueprintable)
struct FWeaponData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MaxAmmo;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int AmmoPerClip;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int InitialClips;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EAmmoType AmmoType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeBetweenShots;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float NoAnimReloadDuration;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool CanZoom;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ZoomFOV;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool CanSwapForSameWeapon;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MeleeDamage;
};

USTRUCT(Blueprintable)
struct FRecoilData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RecoilRiseTime;                       
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RecoilTotalTime;                      
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float VerticalRecoilAmount;                 

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HorizontalRecoilAmount;               

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RecoilKick;                           

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float VisualRecoil;                         
};

USTRUCT(Blueprintable)
struct FReticleData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldShowOuterCircle;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* OuterCircleImage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float OuterCircleRadius;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldShowInnerCircle;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* InnerCircleImage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float InnerCircleRadius;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldShowDot;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShouldShowCrosshair;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* CrosshairBarImage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D CrosshairIndSize;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CrosshairOffset;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* ZoomImage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* HitMarkerImage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* HeadshotMarkerImage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* KillMarkerImage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HitMarkerScale;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ReticleOpacity;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ReticleScale;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor ReticleColor;
};

USTRUCT(Blueprintable)
struct FAutoAimData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AutoAimRadius;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AutoAimRadiusZoomed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AutoAimRange;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MagnetismRange;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MagnetismAngle;
};

USTRUCT(Blueprintable)
struct FWeaponAnimMontage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimMontage* FPP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimMontage* TPP;
};

USTRUCT(Blueprintable)
struct FWeaponBlendSpace1D
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBlendSpace1D* FPP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UBlendSpace1D* TPP;
};

USTRUCT(Blueprintable)
struct FWeaponAnimSequence
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimSequence* FPP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimSequence* TPP;
};

USTRUCT(Blueprintable)
struct FWeaponAnimList
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FWeaponBlendSpace1D WalkBlendSpace;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FWeaponAnimSequence SprintAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FWeaponAnimSequence JumpStartAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FWeaponAnimSequence JumpLoopAnim;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FWeaponAnimSequence JumpEndAnim;
};

USTRUCT(Blueprintable)
struct FRocketStateSpecificMontages
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FWeaponAnimMontage EmptyMontage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FWeaponAnimMontage FullMontage;
};

USTRUCT(Blueprintable)
struct FLineTraceGunData
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WeaponSpread;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WeaponSpreadZoomed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float FiringSpreadIncrement;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float FiringSpreadIncrementZoomed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float FiringSpreadMax;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float FiringSpreadMaxZoomed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector2D> SpreadPattern;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WeaponRange;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DamageDropOffDistance1;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DamageDropOffDistance2;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DamageDropOffModifier;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HitDamage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HeadShotDamage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UDamageType> DamageType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ClientSideHitLeeway;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AllowedViewDotHitDir;
};

USTRUCT(Blueprintable)
struct FLineTraceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector_NetQuantize StartTrace;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector_NetQuantize EndTrace;
};

USTRUCT(Blueprintable)
struct FLineTraceHitResult
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bBlockingHit;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bShotThruPortal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Distance;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector_NetQuantize ImpactPoint;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector_NetQuantizeNormal ImpactNormal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector_NetQuantize TraceStart;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector_NetQuantize TraceEnd;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TWeakObjectPtr<AActor> Actor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName BoneName;
};

USTRUCT(Blueprintable)
struct FBurstLineTraceGunData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NumberOfBurstShots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TimeBetweenBurstShots;
};

USTRUCT(Blueprintable)
struct FPWPointDamageEvent : public FPointDamageEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bThruPortal;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ShotNumber;
};

USTRUCT(Blueprintable)
struct FDamageEvents
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<struct FPWPointDamageEvent> DmgEvents;
};

USTRUCT(Blueprintable)
struct FDecalData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterial* DecalMaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DecalSize;                         
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float LifeSpan;                          
};

/**
 *
 */
UCLASS(Blueprintable)
class PORTALWARSGLOBALS_API UPortalWarsGlobals : public UObject
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<ECustomizationType, FText> CustomizationTypeText;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<ECustomizationType, FText> CustomizationCategoryText;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<ECustomizationRarity, FText> CustomizationRarityText;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<ECustomizationRarity, FLinearColor> CustomizationRarityColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<ECustomizationType, UDataTable*> CustomizationTables;         
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Weapons;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Maps;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* GameModes;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Medals;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EChallengeType, UDataTable*> ChallengeTables;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* CheckInRewards;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* PlayStreakRewards;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Progression;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* BattlePass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<ERewardType, UTexture2D*> RewardIcons;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Ranks;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Playlists;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Regions;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* MicroTxnPurchasables;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Redeemables;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Announcer;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* BotProfiles;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* CustomBotProfiles;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* BannedWords;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* NiceTexts;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* CustomReticles;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* DefaultAvatar;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Tutorial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* XboxButtons;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* MouseButtons;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UDataTable* Tips;
};
