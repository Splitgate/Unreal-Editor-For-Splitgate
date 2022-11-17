// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"

#include "PortalWall.generated.h"

UCLASS()
class PORTALWARS_API APortalWall : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Wall Config")
	UStaticMeshComponent* PortalWallMesh;        
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Wall Config")
	bool ValidForAI;                            
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Wall Config")
	bool IsDoubleSided;                         
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Wall Config")
	bool ShouldDisableForCTF;                   
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Wall Config")
	AActor* Goal;        
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Wall Config")
	TArray<AStaticMeshActor*> Blocks;     
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Wall Config")
	int32 HiddenUntilGoal;                      

	UFUNCTION(BlueprintCallable)
	void DisablePortalWall() {};
};
