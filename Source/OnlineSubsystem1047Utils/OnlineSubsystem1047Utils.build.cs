using UnrealBuildTool;
 
public class OnlineSubsystem1047Utils : ModuleRules
{
	public OnlineSubsystem1047Utils(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine"});
 
		PublicIncludePaths.AddRange(new string[] {"OnlineSubsystem1047Utils/Public"});
		PrivateIncludePaths.AddRange(new string[] {"OnlineSubsystem1047Utils/Private"});
	}
}