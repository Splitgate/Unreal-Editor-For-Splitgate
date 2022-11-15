#include "OnlineSubsystem1047Utils.h"

DEFINE_LOG_CATEGORY(OnlineSubsystem1047Utils);

#define LOCTEXT_NAMESPACE "FOnlineSubsystem1047Utils"

void FOnlineSubsystem1047Utils::StartupModule()
{
	UE_LOG(OnlineSubsystem1047Utils, Warning, TEXT("OnlineSubsystem1047Utils module has been loaded"));
}

void FOnlineSubsystem1047Utils::ShutdownModule()
{
	UE_LOG(OnlineSubsystem1047Utils, Warning, TEXT("OnlineSubsystem1047Utils module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FOnlineSubsystem1047Utils, OnlineSubsystem1047Utils)