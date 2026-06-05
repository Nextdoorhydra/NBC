// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NBC_Project_Chpater3 : ModuleRules
{
	public NBC_Project_Chpater3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
