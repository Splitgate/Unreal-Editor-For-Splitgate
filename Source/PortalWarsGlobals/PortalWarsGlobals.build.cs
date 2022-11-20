using UnrealBuildTool;
 
public class PortalWarsGlobals : ModuleRules
{
	public PortalWarsGlobals(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "MediaAssets", "InputCore" });
 
		PublicIncludePaths.AddRange(new string[] {"PortalWarsGlobals/Public"});
		PrivateIncludePaths.AddRange(new string[] {"PortalWarsGlobals/Private"});
	}
}