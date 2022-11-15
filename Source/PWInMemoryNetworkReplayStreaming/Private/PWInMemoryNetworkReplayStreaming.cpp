#include "PWInMemoryNetworkReplayStreaming.h"

DEFINE_LOG_CATEGORY(PWInMemoryNetworkReplayStreaming);

#define LOCTEXT_NAMESPACE "FPWInMemoryNetworkReplayStreaming"

void FPWInMemoryNetworkReplayStreaming::StartupModule()
{
	UE_LOG(PWInMemoryNetworkReplayStreaming, Warning, TEXT("PWInMemoryNetworkReplayStreaming module has been loaded"));
}

void FPWInMemoryNetworkReplayStreaming::ShutdownModule()
{
	UE_LOG(PWInMemoryNetworkReplayStreaming, Warning, TEXT("PWInMemoryNetworkReplayStreaming module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPWInMemoryNetworkReplayStreaming, PWInMemoryNetworkReplayStreaming)