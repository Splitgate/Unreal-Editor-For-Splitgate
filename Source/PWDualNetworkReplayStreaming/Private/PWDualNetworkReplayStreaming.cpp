#include "PWDualNetworkReplayStreaming.h"

DEFINE_LOG_CATEGORY(PWDualNetworkReplayStreaming);

#define LOCTEXT_NAMESPACE "FPWDualNetworkReplayStreaming"

void FPWDualNetworkReplayStreaming::StartupModule()
{
	UE_LOG(PWDualNetworkReplayStreaming, Warning, TEXT("PWDualNetworkReplayStreaming module has been loaded"));
}

void FPWDualNetworkReplayStreaming::ShutdownModule()
{
	UE_LOG(PWDualNetworkReplayStreaming, Warning, TEXT("PWDualNetworkReplayStreaming module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPWDualNetworkReplayStreaming, PWDualNetworkReplayStreaming)