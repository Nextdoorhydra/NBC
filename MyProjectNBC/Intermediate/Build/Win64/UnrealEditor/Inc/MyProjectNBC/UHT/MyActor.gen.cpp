// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProjectNBC/MyActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
MYPROJECTNBC_API UClass* Z_Construct_UClass_AMyActor();
MYPROJECTNBC_API UClass* Z_Construct_UClass_AMyActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_MyProjectNBC();
// End Cross Module References

// Begin Class AMyActor Function TiggerCustomEvent
struct Z_Construct_UFunction_AMyActor_TiggerCustomEvent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyActor_TiggerCustomEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyActor, nullptr, "TiggerCustomEvent", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyActor_TiggerCustomEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyActor_TiggerCustomEvent_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyActor_TiggerCustomEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyActor_TiggerCustomEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyActor::execTiggerCustomEvent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TiggerCustomEvent();
	P_NATIVE_END;
}
// End Class AMyActor Function TiggerCustomEvent

// Begin Class AMyActor
void AMyActor::StaticRegisterNativesAMyActor()
{
	UClass* Class = AMyActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "TiggerCustomEvent", &AMyActor::execTiggerCustomEvent },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyActor);
UClass* Z_Construct_UClass_AMyActor_NoRegister()
{
	return AMyActor::StaticClass();
}
struct Z_Construct_UClass_AMyActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyActor.h" },
		{ "ModuleRelativePath", "MyActor.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyActor_TiggerCustomEvent, "TiggerCustomEvent" }, // 3355381707
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMyActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProjectNBC,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyActor_Statics::ClassParams = {
	&AMyActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyActor()
{
	if (!Z_Registration_Info_UClass_AMyActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyActor.OuterSingleton, Z_Construct_UClass_AMyActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyActor.OuterSingleton;
}
template<> MYPROJECTNBC_API UClass* StaticClass<AMyActor>()
{
	return AMyActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyActor);
AMyActor::~AMyActor() {}
// End Class AMyActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_NDH_NBC_MyProjectNBC_Source_MyProjectNBC_MyActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyActor, AMyActor::StaticClass, TEXT("AMyActor"), &Z_Registration_Info_UClass_AMyActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyActor), 2792480336U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_NDH_NBC_MyProjectNBC_Source_MyProjectNBC_MyActor_h_2886076411(TEXT("/Script/MyProjectNBC"),
	Z_CompiledInDeferFile_FID_NDH_NBC_MyProjectNBC_Source_MyProjectNBC_MyActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_NDH_NBC_MyProjectNBC_Source_MyProjectNBC_MyActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
