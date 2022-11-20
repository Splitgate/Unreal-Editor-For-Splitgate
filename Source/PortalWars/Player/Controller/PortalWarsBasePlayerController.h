// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PortalWarsBasePlayerController.generated.h"

UENUM(BlueprintType)
enum class EInputMode : uint8
{
	None = 0,
	UIOnly = 1,
	GameAndUI = 2,
	GameOnly = 3
};

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsBasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	EInputMode InputMode;                                    

	UFUNCTION(BlueprintCallable)
	void ServerKickForInactivity() {};
	
	UFUNCTION(BlueprintCallable)
	void KickForInactivity() {};
};
