// Cardinal Troller.


#include "Gun.h"

AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;

	AmmoCounter = CreateDefaultSubobject<UAmmoCounterWidgetComponent>(TEXT("AmmoCounter"));
	ChargeCounter = CreateDefaultSubobject<UAmmoCounterWidgetComponent>(TEXT("ChargeCounter"));
}

void AGun::ServerSpawnGrenade(const FVector_NetQuantize& Origin, const FVector_NetQuantizeNormal& Dir)
{
}

void AGun::ServerGoToState(EWeaponState NewState)
{
}

void AGun::PlayWeaponSound(UObject* Sound)
{
}

void AGun::OnRep_CurrentState(EWeaponState PrevState)
{
}

void AGun::OnRep_AmmoInClip()
{
}

void AGun::OnGunImageLoaded_Implementation()
{
}

void AGun::LoopWeaponSound(bool IsFiring)
{
}

void AGun::ClientStartReload()
{
}
