using UnrealBuildTool;
 
public class PortalWarsMoviePlayer : ModuleRules
{
	public PortalWarsMoviePlayer(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine"});
 
		PublicIncludePaths.AddRange(new string[] {"PortalWarsMoviePlayer/Public"});
		PrivateIncludePaths.AddRange(new string[] {"PortalWarsMoviePlayer/Private"});
	}
}