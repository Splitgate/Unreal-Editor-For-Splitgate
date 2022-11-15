using UnrealBuildTool;
 
public class PWInMemoryNetworkReplayStreaming : ModuleRules
{
	public PWInMemoryNetworkReplayStreaming(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine"});
 
		PublicIncludePaths.AddRange(new string[] {"PWInMemoryNetworkReplayStreaming/Public"});
		PrivateIncludePaths.AddRange(new string[] {"PWInMemoryNetworkReplayStreaming/Private"});
	}
}