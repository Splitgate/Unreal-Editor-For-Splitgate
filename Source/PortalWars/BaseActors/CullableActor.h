// Cardinal troller.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CullableActor.generated.h"

UCLASS()
class PORTALWARS_API ACullableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACullableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
