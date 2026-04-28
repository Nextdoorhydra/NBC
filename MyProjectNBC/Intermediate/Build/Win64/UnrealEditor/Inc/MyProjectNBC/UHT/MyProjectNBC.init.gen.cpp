// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyProjectNBC_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MyProjectNBC;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MyProjectNBC()
	{
		if (!Z_Registration_Info_UPackage__Script_MyProjectNBC.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MyProjectNBC",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xCF26E683,
				0xD4C4C5B3,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MyProjectNBC.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MyProjectNBC.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MyProjectNBC(Z_Construct_UPackage__Script_MyProjectNBC, TEXT("/Script/MyProjectNBC"), Z_Registration_Info_UPackage__Script_MyProjectNBC, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xCF26E683, 0xD4C4C5B3));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
