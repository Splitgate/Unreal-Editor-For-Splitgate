// Copyright 2019 1047 Games, LLC. All Rights Reserved.

#include "PortalWall.h"

APortalWall::APortalWall()
{
	PrimaryActorTick.bCanEverTick = true;

	PortalWallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("portalWallMesh"));
}