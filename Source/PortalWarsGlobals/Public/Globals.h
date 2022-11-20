// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "Animation/AnimSequence.h"
#include "Animation/BlendSpace1D.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/GameMode.h"
#include "Engine/StaticMesh.h"
#include "MediaSource.h"
#include "InputCoreTypes.h"
#include "Globals.generated.h"

// Enums And Structs

UENUM(BlueprintType)
enum class ERegionSelectability : uint8
{
	Matchmaking = 0,
	Custom = 1
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
enum class ECustomizationAvailability : uint8
{
	Normal = 0,
	Default = 1,
	Challenge = 2,
	Reward = 3,
	Store = 4,
	Partner = 5,
	Streamer = 6,
	DLC = 7,
	VIP = 8,
	CreatorCode = 9,
	BattlePass = 10,
	Reserved = 11,
	Developer = 12,
	Decommissioned = 13
};

UENUM(BlueprintType)
enum class EVotingPriority : uint8
{
	Normal = 0,
	High = 1
};

UENUM(BlueprintType)
enum class EPlaylistType : uint8
{
	Unranked = 0,
	Ranked = 1,
	Featured = 2
};

UENUM(BlueprintType)
enum class EGameModeSelectability : uint8
{
	None = 0,
	Custom = 1,
	Standard = 2,
	Hardcore = 3
};

UENUM(BlueprintType)
enum class EReplayCameraMode : uint8
{
	None = 0,
	Free = 1,
	FirstPerson = 2,
	ThirdPerson = 3
};

UENUM(BlueprintType)
enum class EBodyPart : uint8
{
	Torso = 0,
	Head = 1,
	Feet = 2
};

UENUM(BlueprintType)
enum class EHitDirection : uint8
{
	F = 0,
	FL = 1,
	FR = 2,
	B = 3,
	BL = 4,
	BR = 5,
	L = 6,
	R = 7
};

UENUM(BlueprintType)
enum class EPWHitType : uint8
{
	Normal = 0,
	Headshot = 1,
	Death = 2,
};

UENUM(BlueprintType)
enum class EMapSelectability : uint8
{
	None = 0,
	Default = 1,
	QA = 2
};

UENUM(BlueprintType)
enum class EBotDifficulty : uint8
{
	Easy = 0,
	Medium = 1,
	Hard = 2
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
enum class EServerType : uint8
{
	LAN = 0,
	Unranked = 1,
	Ranked = 2,
	Custom = 3,
	Standard = 4,
	Simulation = 5,
	WaitingArea = 6
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
struct FTransform_NetQuantize : public FTransform
{
	GENERATED_BODY()
};

USTRUCT(Blueprintable)
struct FTakeHitInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	uint8 ActualDamage;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float LastTakeHitTime;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FDamageEvent DamageEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EHitDirection HitDirection;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EBodyPart BodyPart;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TWeakObjectPtr<class ACharacter> PawnInstigator;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EPWHitType HitType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	uint8 EnsureReplicationByte;
};

USTRUCT(Blueprintable)
struct FCheatViolations
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int> Counts;
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

USTRUCT(Blueprintable)
struct FGameConfig
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ServerName;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MapID;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int GameModeID;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int MatchTime;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int ScoreLimit;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int RespawnTime;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int PrimaryWeaponID;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int SecondaryWeaponID;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bPickupsEnabled;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bBotsEnabled;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EBotDifficulty BotDifficulty;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bShouldShowRadar;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bEnableBoundaries;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bEnableJetpack;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bEnableSprint;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bEnablePortalGun;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bUnlimitedAmmo;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bUnlimitedClipSize;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bHeadshotsOnly;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bBigHeadMode;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WalkSpeedModifier;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float JumpHeightModifier;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float GravityModifier;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ThrusterPackFuelModifier;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ThrusterPackBoostModifier;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MeleeDmgModifier;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HealthModifier;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bRandomHillsEnabled;
};

USTRUCT(Blueprintable)
struct FTextTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Text;
};

USTRUCT(Blueprintable)
struct FBotProfileData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Name;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UTexture2D> Avatar;      
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString AvatarPath;                     
};

USTRUCT(Blueprintable)
struct FStringTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString String;
};

USTRUCT(Blueprintable)
struct FAnnouncerEvent : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString EventName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText SubtitleText;
};

USTRUCT(Blueprintable)
struct FTipData : public FTextTableRow
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool KeyboardOnly;
};

USTRUCT(Blueprintable)
struct FMouseButtonData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FKey Key;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* Icon;
};

USTRUCT(Blueprintable)
struct FGamepadButtonData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FKey Key;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName ActionName;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* Icon;
};

USTRUCT(Blueprintable)
struct FPWTableRowBase : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ID;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText DisplayName;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UTexture2D> DisplayImage;
};

USTRUCT(Blueprintable)
struct FTutorialStepData
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Description;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 GoalID;
};

USTRUCT(Blueprintable)
struct FSubtitleInfo
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 StartTimeSeconds;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 EndTimeSeconds;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString TableKey;
};

USTRUCT(Blueprintable)
struct FVideoInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMediaSource* MediaSource;  

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FSubtitleInfo> Subtitles;
};

USTRUCT(Blueprintable)
struct FTutorialStageData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FTutorialStepData> Steps;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVideoInfo VideoInfo;
};

USTRUCT(Blueprintable)
struct FMapData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString MapName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<EMapSelectability> Selectability;
};

USTRUCT(Blueprintable)
struct FGameModeData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGameMode> DefaultClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Alias;                     
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Description;               
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText ScoreFormatText;           
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxPlayers;                
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString SoundName;                 
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<EGameModeSelectability> Selectability;             
};

USTRUCT(Blueprintable)
struct FMapModeCombos
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ModeID;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int32> MapIDs;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EVotingPriority VotingPriority;
};

USTRUCT(Blueprintable)
struct FPlaylistData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString InternalName;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EPlaylistType PlaylistType;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Description;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxPartySize;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FMapModeCombos> MapModeCombos;
};

USTRUCT(Blueprintable)
struct FCustomizationItem : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ECustomizationType CustomizationType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ECustomizationRarity Rarity;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ECustomizationAvailability Availability;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString AvailabilityInfo;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 SecondaryCurrencyCost;
};

USTRUCT(Blueprintable)
struct FSkin : public FCustomizationItem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UMaterialInstance>      MaterialInstance;
};

USTRUCT(Blueprintable)
struct FWeaponSkin : public FSkin
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<USkeletalMesh> Mesh1P;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UStaticMesh> Mesh3P;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UTexture2D> Decal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName AmmoCounterSocketName;
};

USTRUCT(Blueprintable)
struct FSuitSkin : public FSkin
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText SuitName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<USkeletalMesh> Mesh3P;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<USkeletalMesh> FemaleMesh3P;
};

USTRUCT(Blueprintable)
struct FChestSkin : public FSuitSkin
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<USkeletalMesh> Mesh1P;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName JetpackSocketName;
};

USTRUCT(Blueprintable)
struct FJetpackSkin : public FSkin
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText JetpackName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UStaticMesh> FlamesMesh;
};

USTRUCT(Blueprintable)
struct FPortalSkin : public FSkin
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UStaticMesh> Mesh;
};

USTRUCT(Blueprintable)
struct FPortalGunSkin : public FWeaponSkin
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText PortalGunName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UAnimSequence> FireAnimation;
};

USTRUCT(Blueprintable)
struct FNameTagItem : public FCustomizationItem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor TextColor;         
};

USTRUCT(Blueprintable)
struct FEmote : public FCustomizationItem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UAnimSequence> AnimationSequence;
};

USTRUCT(Blueprintable)
struct FEmblemItem : public FCustomizationItem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UTexture2D> EmblemTexture;
};

USTRUCT(Blueprintable)
struct FRewardData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ERewardType RewardType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CustomizationType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 RewardValue;
};

USTRUCT(Blueprintable)
struct FChallengeData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EChallengeType ChallengeType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 TargetValue;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FRewardData Reward;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 GroupId;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString GroupName;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString StatType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FString> ExcludedPlaylists;
};

USTRUCT(Blueprintable)
struct FBattlePassData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MinXP;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxXP;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FRewardData> FreeRewards;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FRewardData> PremiumRewards;
};

USTRUCT(Blueprintable)
struct FMicroTxnPurchasable : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Price;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrencyAmount;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 BonusCurrencyAmount;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, int32> Prices;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Description;
};

USTRUCT(Blueprintable)
struct FRankData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 RankDownXP;
			
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 RankUpXP;
};

USTRUCT(Blueprintable)
struct FProgressionData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 XPDifference;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 LevelUpXP;                                     
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FRewardData Reward;                                  
};

USTRUCT(Blueprintable)
struct FRegionData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PingURL;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString InternalName;                                
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<ERegionSelectability> Selectability;          
};

USTRUCT(Blueprintable)
struct FPlayStreakData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FRewardData Reward;
};

USTRUCT(Blueprintable)
struct FCheckInData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FRewardData> Rewards;   
};

USTRUCT(Blueprintable)
struct FRedeemableData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CurrencyCost;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Amount;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Description;
};

USTRUCT(Blueprintable)
struct FMedalData : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString SoundName; 
};

USTRUCT(Blueprintable)
struct FWeaponMetadata : public FPWTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<class AActor> DefaultClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CrosshairWeaponID;
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
