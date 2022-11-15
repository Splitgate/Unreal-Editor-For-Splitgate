// Cardinal Troller.


#include "RailGun.h"

ARailGun::ARailGun()
{
	PrimaryActorTick.bCanEverTick = true;

	ChargePSC_1P = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ChargePSC_1P"));
	ChargePSC_3P = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ChargePSC_3P"));
}