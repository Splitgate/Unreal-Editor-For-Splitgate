// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/Controller/PortalWarsBasePlayerController.h"
#include "../../Portals/Portal.h"
#include "Engine/SceneCapture2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Globals.h"

#include "PortalWarsPlayerController.generated.h"

UENUM(BlueprintType)
enum class EChatType : uint8
{
	General = 0,
	Team = 1
};

USTRUCT(Blueprintable)
struct FActorOriginAndExtent
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* Actor;
};

USTRUCT(Blueprintable)
struct FTextChatData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString SenderName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	struct FUniqueNetIdRepl SenderID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString SenderText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EChatType ChatType;
};

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsPlayerController : public APortalWarsBasePlayerController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	APortal* LeftPortal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	APortal* RightPortal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	ASceneCapture2D* LeftPortalSceneCapture;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	ASceneCapture2D* RightPortalSceneCapture;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	TSubclassOf<ASceneCapture2D> PortalSceneCaptureClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	UTextureRenderTarget2D* LeftPortalRenderTarget;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	UTextureRenderTarget2D* RightPortalRenderTarget;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
	float MaxFPS;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
	class UUserWidget* PauseMenu;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
	float PredictionFudgeFactor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
	float MaxPredictionPing;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
	float MaxMeleePredictionPing;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	TArray<FActorOriginAndExtent> ActorOriginAndExtentList;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
	UObject* Killcam;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Player Config")
	UMaterial* OutlinePPMaterial;

		
	UFUNCTION(BlueprintCallable)
	void SpawnPickup(FName PickupClassName) {};
		
	UFUNCTION(BlueprintCallable)
	void Slowmo(float TimeDilation) {};
		
	UFUNCTION(BlueprintCallable)
	void ServerSpawnPickup(FName PickupClassName) {};
		
	UFUNCTION(BlueprintCallable)
	void ServerSlomo(float TimeDilation) {};
		
	UFUNCTION(BlueprintCallable)
	void ServerReportPlayerById(FUniqueNetIdRepl& PlayerIdToReport, int32 ReportCategory, const FString& Description) {};
		
	UFUNCTION(BlueprintCallable)
	void ServerReportPlayer(class APlayerState* PlayerStateToReport, int32 ReportCategory, const FString& Description) {};
		
	//UFUNCTION(BlueprintNativeEvent)
	//void ServerReceiveRanks(TArray<FUserRankInfo>& PlayerRanks) {};
	//	
	//UFUNCTION(BlueprintNativeEvent)
	//void ServerReceiveCustomizations(TArray<FCustomizationInfo>& ChosenCustomizations) {};
		
	UFUNCTION(BlueprintCallable)
	void ServerKickPlayer(class APlayerState* PlayerStateToKick) {};
		
	UFUNCTION(BlueprintCallable)
	void ServerEndMatch() {};
		
	UFUNCTION(BlueprintCallable)
	void ServerEnableGodMode() {};
		
	UFUNCTION(BlueprintCallable)
	void ServerBroadcastChatMessage(const FTextChatData& InData) {};
		
	UFUNCTION(BlueprintCallable)
	void SendRanksToServer() {};
		
	UFUNCTION(BlueprintCallable)
	void ReportPlayer(class APlayerState* PlayerStateToReport, int32 ReportCategory, const FString& Description) {};
		
	UFUNCTION(BlueprintPure)
	bool ProjectWorldLocationToScreenCustom(const FVector& WorldLocation, FVector2D& ScreenLocation, bool bPlayerViewportRelative) { return true; };
		
	UFUNCTION(BlueprintCallable)
	void PlayEmote() {};

	UFUNCTION(BlueprintNativeEvent)
	void OnPauseMenuClosed();

	UFUNCTION(BlueprintPure)
	int32 GetTeamNum() { return 0; };

	UFUNCTION(BlueprintCallable)
	void EnableGodMode() {};
		
	UFUNCTION(BlueprintCallable)
	void ClientUpdateChat(const FTextChatData& InData) {};
		
	UFUNCTION(BlueprintCallable)
	void ClientSetSpectatorCamera(const FVector& CameraLocation, const FRotator& CameraRotation) {};
		
	UFUNCTION(BlueprintCallable)
	void ClientSetMatchResult(bool bIsWinner, bool bIsTie, int32 Placement) {};
		
	UFUNCTION(BlueprintCallable)
	void ClientNotifyTeammateTeabagConfirmed() {};
		
	UFUNCTION(BlueprintCallable)
	void ClientNotifyTeabagDenied() {};
		
	UFUNCTION(BlueprintCallable)
	void ClientNotifyTeabagConfirmed() {};
		
	UFUNCTION(BlueprintCallable)
	void ClientNotifyEnemyDeniedTeabag() {};
		
	UFUNCTION(BlueprintCallable)
	void ClientNotifyDamageTaken(const FVector_NetQuantize& HitLocation) {};
		
	UFUNCTION(BlueprintCallable)
	void ClientNotifyCountdown(int32 CountdownTime) {};
		
	UFUNCTION(BlueprintCallable)
	void ClientNotifyCausedHit(EPWHitType HitType) {};
		
	UFUNCTION(BlueprintCallable)
	void ClientNotifyAlive() {};
		
	UFUNCTION(BlueprintCallable)
	void ClientHearAkEventAtLocation(class UObject* EventToPost, const FVector_NetQuantize& SoundLocation, FRotator& SoundRotation) {};
		
	UFUNCTION(BlueprintCallable)
	void ClientHearAkEvent(class UObject* EventToPost, class UObject* AkComponent) {};
		
	UFUNCTION(BlueprintCallable)
	void ClientGenericInitialization() {};
		
	UFUNCTION(BlueprintCallable)
	void ClientGameStarted() {};
		
	UFUNCTION(BlueprintCallable)
	void ClientCountdownStarted() {};

};
