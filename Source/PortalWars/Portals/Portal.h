// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "BaseActors/CullableActor.h"
#include "Portal.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API APortal : public ACullableActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	FVector PortalGrow_Scale_Start;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	float PortalGrow_TotalSeconds;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	bool IsLeftPortal;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	USceneComponent* Root;  

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	USceneComponent* AkPortal;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* PortalAmb_PlayEvent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	UObject* PortalAmb_StopEvent;

	//class APortalWarsCharacter* MyPawn;
	//class APortalWarsPlayerState* MyPlayerState;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	APortal* LinkedPortal;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    int OutlineColorIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    int LeftPortalStencilValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    int RightPortalStencilValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    FLinearColor UnlinkedPortalColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    FLinearColor LeftPortalColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    FLinearColor RightPortalColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Mesh")
	UStaticMeshComponent* PortalMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Mesh")
	UStaticMeshComponent* PortalCollisionFrameMesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Mesh")
	UStaticMeshComponent* PortalRingMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
	class APortalWall* PortalWall;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Mesh")
	UStaticMeshComponent* SmallPortalOverlapBox;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Mesh")
	UStaticMeshComponent* LargePortalOverlapBox;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Mesh")
	UStaticMeshComponent* PortalCullingWall;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    UMaterialInstanceDynamic* PortalDynamicMaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    UMaterialInstance* DefaultPortalMaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    UMaterial* RenderedPortalMaterial;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    FLinearColor FriendlyPortalColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    FLinearColor EnemyPortalColor;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    FLinearColor AlphaTeamPortalColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Portal Config")
    FLinearColor BravoTeamPortalColor;
	//UPortalWarsIndicatorWidget* PortalIndicatorWidget;

	UFUNCTION(BlueprintCallable)
	void UpdateSkins() {};
	
	UFUNCTION(BlueprintCallable)
	void PortalShrink_StartAnim() {};
	
	UFUNCTION(BlueprintCallable)
	void PortalGrow_StartAnim() {};
	
	UFUNCTION(BlueprintCallable)
	void OnRep_MyPawn() {};
	
	UFUNCTION(BlueprintCallable)
	void InitializePortalColor() {};
	
	UFUNCTION(BlueprintCallable)
	void InitializePortal() {};

	UFUNCTION(BlueprintNativeEvent)
	void EndOverlapSmallBox(UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex);
	
	UFUNCTION(BlueprintNativeEvent)
	void EndOverlapLargeBox(UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex);
	
	UFUNCTION(BlueprintNativeEvent)
	void BeginOverlapSmallBox(UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, FHitResult& SweepResult);
	
	UFUNCTION(BlueprintNativeEvent)
	void BeginOverlapLargeBox(UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, struct FHitResult& SweepResult);
};
