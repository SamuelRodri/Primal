// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Primal : ModuleRules
{
	public Primal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Primal",
			"Primal/Variant_Platforming",
			"Primal/Variant_Platforming/Animation",
			"Primal/Variant_Combat",
			"Primal/Variant_Combat/AI",
			"Primal/Variant_Combat/Animation",
			"Primal/Variant_Combat/Gameplay",
			"Primal/Variant_Combat/Interfaces",
			"Primal/Variant_Combat/UI",
			"Primal/Variant_SideScrolling",
			"Primal/Variant_SideScrolling/AI",
			"Primal/Variant_SideScrolling/Gameplay",
			"Primal/Variant_SideScrolling/Interfaces",
			"Primal/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
