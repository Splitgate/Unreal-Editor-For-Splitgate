// Cardinal troller.

#include "BaseGun.h"

ABaseGun::ABaseGun()
{
	PrimaryActorTick.bCanEverTick = true;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent")));

	MuzzlePSC_1P = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MuzzlePSC_1P"));
	MuzzlePSC_3P = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MuzzlePSC_3P"));

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh1P"));
	Mesh3P = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh3P"));
}

void ABaseGun::UpdateSkins()
{
}

USkeletalMeshComponent* ABaseGun::GetMesh1P()
{
	return Mesh1P;
}

int32 ABaseGun::GetControllingTeam()
{
	return 0;
}

void ABaseGun::ClientRemoved_Implementation()
{
}