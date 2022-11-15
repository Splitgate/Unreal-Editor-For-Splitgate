#include "PortalWarsMoviePlayer.h"

DEFINE_LOG_CATEGORY(PortalWarsMoviePlayer);

#define LOCTEXT_NAMESPACE "FPortalWarsMoviePlayer"

void FPortalWarsMoviePlayer::StartupModule()
{
	UE_LOG(PortalWarsMoviePlayer, Warning, TEXT("PortalWarsMoviePlayer module has been loaded"));
}

void FPortalWarsMoviePlayer::ShutdownModule()
{
	UE_LOG(PortalWarsMoviePlayer, Warning, TEXT("PortalWarsMoviePlayer module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPortalWarsMoviePlayer, PortalWarsMoviePlayer)