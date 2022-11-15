// Cardinal Troller.

#pragma once

#include "CoreMinimal.h"
#include "Guns/SpecialItem.h"
#include "FlagItem.generated.h"

/**
 * 
 */
UCLASS()
class PORTALWARS_API AFlagItem : public ASpecialItem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Current Values")
	int TeamIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UMaterialInstance* FriendlyTeamFlagMaterial;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UMaterialInstance* EnemyTeamFlagMaterial;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UMaterialInstance* AlphaTeamFlagMaterial;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon Effects")
	UMaterialInstance* BravoTeamFlagMaterial;

	UFUNCTION(BlueprintCallable)
	void OnRep_Team() {};
};
