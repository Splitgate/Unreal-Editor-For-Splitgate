using UnrealBuildTool;
 
public class PWDualNetworkReplayStreaming : ModuleRules
{
	public PWDualNetworkReplayStreaming(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine"});
 
		PublicIncludePaths.AddRange(new string[] {"PWDualNetworkReplayStreaming/Public"});
		PrivateIncludePaths.AddRange(new string[] {"PWDualNetworkReplayStreaming/Private"});
	}
}