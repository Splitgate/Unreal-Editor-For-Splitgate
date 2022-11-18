// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#include "PortalWarsCharacter.h"

APortalWarsCharacter::APortalWarsCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APortalWarsCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APortalWarsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APortalWarsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APortalWarsCharacter::OnReplayCameraModeChanged_Implementation(enum class EReplayCameraMode NewReplayCameraMode)
{

}

void APortalWarsCharacter::OnGlobalVisionChanged_Implementation()
{

}

void APortalWarsCharacter::OnDeath_Implementation()
{

}

void APortalWarsCharacter::OnComponentHit_Implementation(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, const FVector& NormalImpulse, FHitResult& Hit)
{

}

