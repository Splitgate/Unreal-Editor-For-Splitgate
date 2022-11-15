#include "PortalWarsGlobals.h"

DEFINE_LOG_CATEGORY(PortalWarsGlobals);

#define LOCTEXT_NAMESPACE "FPortalWarsGlobals"

void FPortalWarsGlobals::StartupModule()
{
	UE_LOG(PortalWarsGlobals, Warning, TEXT("PortalWarsGlobals module has been loaded"));
}

void FPortalWarsGlobals::ShutdownModule()
{
	UE_LOG(PortalWarsGlobals, Warning, TEXT("PortalWarsGlobals module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPortalWarsGlobals, PortalWarsGlobals)