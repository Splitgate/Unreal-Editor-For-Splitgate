using UnrealBuildTool;
 
public class PortalWarsEditor : ModuleRules
{
	public PortalWarsEditor(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UnrealEd"});
 
		PublicIncludePaths.AddRange(new string[] {"PortalWarsEditor/Public"});
		PrivateIncludePaths.AddRange(new string[] {"PortalWarsEditor/Private"});
	}
}