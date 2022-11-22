// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Globals1047.generated.h"

USTRUCT(Blueprintable)
struct FUserRankInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString RankType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 RankLevel;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 RankXP;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 GamesPlayedCount;
};

USTRUCT(Blueprintable)
struct FCustomizationInfo
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CustomizationKey;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 CustomizationValue;
};

USTRUCT(Blueprintable)
struct FWeaponStats
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Name;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Kills;                
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ShotsFired;           
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ShotsLanded;          
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 HeadshotsLanded;      
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 HeadshotKills;        
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 KillsThruPortal;      
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MeleeKills;           
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Collaterals;          
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 PossessionSecs;       
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DamageDealt;          
};

USTRUCT(Blueprintable)
struct FUserStats
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 GamesPlayed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 GamesWon;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Kills;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Assists;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Deaths;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Suicides;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Teabags;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MeleeKills;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 PortalKills;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 KillsThruPortal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DoubleKills;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 TripleKills;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 QuadKills;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 QuintKills;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 SexKills;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Killstreak1;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Killstreak2;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Killstreak3;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Killstreak4;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Killstreak5;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Killstreak6;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DamageDealt;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FWeaponStats> Weapons;
};

USTRUCT(Blueprintable)
struct FEndGamePlayerStatsInfo : public FUserStats
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Points;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 EnemyPortalsDestroyed;              
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 AllyPortalsEntered;                 
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 EnemyPortalsEntered;                
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 OwnPortalsEntered;                  
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 TimePlayed;                         
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AdaptiveDifficultyAverage;          
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 PortalsSpawned;                     
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 DistancePortaled;                   
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 HighestConsecutiveKills;            
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 HillsCaptured;                      
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 HillsNeutralized;                   
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 KillsOnHill;                        
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 EnemyKillsOnHill;                   
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 FlagsPickedUp;                      
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 FlagsReturned;                      
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 FlagKills;                          
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 FlagCarrierKills;                   
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 OddballsPickedUp;                   
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 OddballKills;                       
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 OddballCarrierKills;                
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 KillsAsVIP;                         
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 TeabagsDenied;                      
};

USTRUCT(Blueprintable)
struct FEndGamePlayerInfo
{
	GENERATED_BODY()

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PlatformId;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Team;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FCustomizationInfo> Customizations;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FEndGamePlayerStatsInfo Stats;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bQuitter;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PlayerName;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FUserRankInfo PlaylistRank;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsABot;
};

/**
 * 
 */
UCLASS()
class ONLINESUBSYSTEM1047UTILS_API UGlobals1047 : public UObject
{
	GENERATED_BODY()
	
};
