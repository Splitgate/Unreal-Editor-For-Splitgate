// Copyright 2019 1047 Games, LLC. All Rights Reserved.


#include "PortalWarsTeamStart.h"

void APortalWarsTeamStart::OnConstruction(const FTransform& Transform)
{
	GetGoodSprite()->ScreenSize = 0.5f;
	GetGoodSprite()->bIsScreenSizeScaled = true;

	if (SpawnTeam == 0)
	{
		GetGoodSprite()->SetSprite(AmbientTeamTexture);
	}

	if (SpawnTeam == 1)
	{
		GetGoodSprite()->SetSprite(BlueTeamTexture);
	}

	if (SpawnTeam == 2)
	{
		GetGoodSprite()->SetSprite(RedTeamTexture);
	}

	if (SpawnTeam >= 3)
	{
		GetGoodSprite()->SetSprite(AmbientTeamTexture);
	}
}