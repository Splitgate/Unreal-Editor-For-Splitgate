// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/TeleportableActor.h"
#include "PortalWarsPickup.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortalWarsPickup : public ATeleportableActor
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	float PickupLifetime;                          
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	float InitVelocityMultiplier;                    
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	bool ValidForAI;                                 
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	bool AllowAutoPickup;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	bool AllowManualPickup;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	bool bIsGravityEnabled;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	float PickupDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	AActor* Goal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Pickup Config")
	int32 HiddenUntilGoal;                           
};
