// Cardinal troller.

#pragma once

#include "CoreMinimal.h"
#include "BaseActors/CullableActor.h"
#include "Globals.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "BaseGun.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API ABaseGun : public ACullableActor
{
	GENERATED_BODY()
	
public:

	ABaseGun();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Muzzle Config")
	FName MuzzleAttachPoint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Muzzle Config")
	UParticleSystem* MuzzleFX;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Muzzle Config")
	FVector Muzzle1pScale;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Muzzle Config")
	FVector Muzzle3pScale;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Muzzle Config")
	UParticleSystemComponent* MuzzlePSC_1P;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Muzzle Config")
	UParticleSystemComponent* MuzzlePSC_3P;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Muzzle Config")
	uint8 bLoopedMuzzleFX : 1;

	UPROPERTY(BlueprintReadWrite, Category = "Character")
	APawn* MyPawn; //APortalWarsCharacter* MyPawn;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Character")
	USkeletalMeshComponent* Mesh1P;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Character")
	UStaticMeshComponent* Mesh3P;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
	ECustomizationType SkinType;

public:

	UFUNCTION(BlueprintCallable)
	void UpdateSkins();

	UFUNCTION(BlueprintPure)
	USkeletalMeshComponent* GetMesh1P();
	
	UFUNCTION(BlueprintPure)
	int32 GetControllingTeam();

	UFUNCTION(BlueprintNativeEvent)
	void ClientRemoved();
};