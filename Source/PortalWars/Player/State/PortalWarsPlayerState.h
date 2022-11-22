// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Globals.h"
#include "Globals1047.h"

#include "PortalWarsPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	uint8 TeamNum;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 NumKills;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	uint8 KillStreak;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	uint8 MultiKillCounter;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 NumDeaths;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 NumAssists;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	TMap<APortalWarsPlayerState*, float> DamagePlayers;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	uint8 FirstBloods : 1;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 Revenges;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 KingSlayers;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 MeleeKills;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 Headshots;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 PortalKills;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 KillsThruPortal;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int32 Teabags;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Info")
	FEndGamePlayerInfo PostGameStats;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	bool bIsAdmin;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Customizations")
	TArray<FCustomizationInfo> PlayerCustomizations;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Customizations")
	TArray<UObject*> CachedCustomizationObjects;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Customizations")
	UTexture2D* PlayerAvatar;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Info")
	TArray<FUserRankInfo> PlayerRanks;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Info")
	FString InternalUniqueId;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Devious")
	uint8 bQuitter : 1;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Devious")
	bool bIsFlagged;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Customizations")
	FBotProfileData BotProfile;

	UFUNCTION(BlueprintCallable)
	void SetTeamNum(uint8 NewTeamNumber) {};
	
	UFUNCTION(BlueprintCallable)
	void SetPlayerAvatar(UTexture2D* Avatar) {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Team() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Teabags() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Revenge() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Ranks() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_PostGameStats() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_PortalKills(int32 OldPortalKills) {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_PlayerCustomizations() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_MultiKillCounter(uint8 OldMultiKillCounter) {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_MeleeKills() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_KingSlayer() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_KillStreak(uint8 OldKillStreak) {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_KillsThruPortal(int32 OldKillsThruPortal) {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Kill(int32 OldKills) {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_IsFlagged() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_IsAdmin() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Headshots(int32 OldHeadshots) {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_FirstBlood() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Death() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_BotProfile() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_Assist(int32 OldAssists) {};
	
	UFUNCTION(BlueprintNativeEvent)
	void OnCustomizationsLoaded();
	
	UFUNCTION(BlueprintNativeEvent)
	void OnBotAvatarLoaded();
	
	UFUNCTION(BlueprintCallable)
	void LoadPlayerAvatar() {};
	
	UFUNCTION(BlueprintPure)
	uint8 GetTeamNum() { return TeamNum; };
	
	UFUNCTION(BlueprintPure)
	FString GetShortPlayerName() { return GetPlayerName(); };
	
	UFUNCTION(BlueprintPure)
	float GetScore() { return Score; };
	
	UFUNCTION(BlueprintPure)
	int32 GetKills() { return NumKills; };
	
	UFUNCTION(BlueprintPure)
	int32 GetDeaths() { return NumDeaths; };
	
	UFUNCTION(BlueprintPure)
	int32 GetAssists() { return NumAssists; };
	
	UFUNCTION(BlueprintCallable)
	void ClientReconnected() {};
	
	UFUNCTION(BlueprintCallable)
	void BroadcastDeath_Multicast(APortalWarsPlayerState* KillerPlayerState, UDamageType* KillerDamageType, APortalWarsPlayerState* KilledPlayerState, bool bIsHeadshot, const TArray<APortalWarsPlayerState*>& DamagePlayerStates, const TArray<float>& DamagePlayerDamages) {};
};
