// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/MyProjectProjectile.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyProjectProjectile() {}
// Cross Module References
	MYPROJECT_API UClass* Z_Construct_UClass_AMyProjectProjectile_NoRegister();
	MYPROJECT_API UClass* Z_Construct_UClass_AMyProjectProjectile();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MyProject();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AMyProjectProjectile::execSetDamage)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Dmg);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDamage(Z_Param_Dmg);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyProjectProjectile::execOnHit)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent);
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_NormalImpulse,Z_Param_Out_Hit);
		P_NATIVE_END;
	}
	void AMyProjectProjectile::StaticRegisterNativesAMyProjectProjectile()
	{
		UClass* Class = AMyProjectProjectile::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHit", &AMyProjectProjectile::execOnHit },
			{ "SetDamage", &AMyProjectProjectile::execSetDamage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics
	{
		struct MyProjectProjectile_eventOnHit_Parms
		{
			UPrimitiveComponent* HitComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComponent;
			FVector NormalImpulse;
			FHitResult Hit;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComponent;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Hit;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_HitComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_HitComponent = { "HitComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyProjectProjectile_eventOnHit_Parms, HitComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_HitComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_HitComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyProjectProjectile_eventOnHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_OtherComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_OtherComponent = { "OtherComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyProjectProjectile_eventOnHit_Parms, OtherComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_OtherComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_OtherComponent_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyProjectProjectile_eventOnHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyProjectProjectile_eventOnHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_Hit_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_Hit_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_HitComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_OtherComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_NormalImpulse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::NewProp_Hit,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Function that is called when the projectile hits something.\n" },
		{ "ModuleRelativePath", "MyProjectProjectile.h" },
		{ "ToolTip", "Function that is called when the projectile hits something." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyProjectProjectile, nullptr, "OnHit", nullptr, nullptr, sizeof(MyProjectProjectile_eventOnHit_Parms), Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyProjectProjectile_OnHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyProjectProjectile_OnHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics
	{
		struct MyProjectProjectile_eventSetDamage_Parms
		{
			int32 Dmg;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Dmg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::NewProp_Dmg = { "Dmg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyProjectProjectile_eventSetDamage_Parms, Dmg), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::NewProp_Dmg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyProjectProjectile.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyProjectProjectile, nullptr, "SetDamage", nullptr, nullptr, sizeof(MyProjectProjectile_eventSetDamage_Parms), Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyProjectProjectile_SetDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyProjectProjectile_SetDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMyProjectProjectile_NoRegister()
	{
		return AMyProjectProjectile::StaticClass();
	}
	struct Z_Construct_UClass_AMyProjectProjectile_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CollisionComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovementComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovementComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileMeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileMeshComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileMaterialInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileMaterialInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Damage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyProjectProjectile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyProjectProjectile_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyProjectProjectile_OnHit, "OnHit" }, // 2243204267
		{ &Z_Construct_UFunction_AMyProjectProjectile_SetDamage, "SetDamage" }, // 3994517874
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyProjectProjectile_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyProjectProjectile.h" },
		{ "ModuleRelativePath", "MyProjectProjectile.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_CollisionComponent_MetaData[] = {
		{ "Category", "Projectile" },
		{ "Comment", "// Sphere collision component.\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyProjectProjectile.h" },
		{ "ToolTip", "Sphere collision component." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_CollisionComponent = { "CollisionComponent", nullptr, (EPropertyFlags)0x00100000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyProjectProjectile, CollisionComponent), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_CollisionComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_CollisionComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMovementComponent_MetaData[] = {
		{ "Category", "Movement" },
		{ "Comment", "// Projectile movement component.\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyProjectProjectile.h" },
		{ "ToolTip", "Projectile movement component." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMovementComponent = { "ProjectileMovementComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyProjectProjectile, ProjectileMovementComponent), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMovementComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMeshComponent_MetaData[] = {
		{ "Category", "Projectile" },
		{ "Comment", "// Projectile mesh\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyProjectProjectile.h" },
		{ "ToolTip", "Projectile mesh" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMeshComponent = { "ProjectileMeshComponent", nullptr, (EPropertyFlags)0x00100000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyProjectProjectile, ProjectileMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMeshComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMaterialInstance_MetaData[] = {
		{ "Category", "Movement" },
		{ "Comment", "// Projectile material\n" },
		{ "ModuleRelativePath", "MyProjectProjectile.h" },
		{ "ToolTip", "Projectile material" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMaterialInstance = { "ProjectileMaterialInstance", nullptr, (EPropertyFlags)0x0010000000030001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyProjectProjectile, ProjectileMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMaterialInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMaterialInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_Damage_MetaData[] = {
		{ "Category", "Damage" },
		{ "ModuleRelativePath", "MyProjectProjectile.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000030001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyProjectProjectile, Damage), METADATA_PARAMS(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_Damage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_Damage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyProjectProjectile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_CollisionComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMovementComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMeshComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_ProjectileMaterialInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyProjectProjectile_Statics::NewProp_Damage,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyProjectProjectile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyProjectProjectile>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyProjectProjectile_Statics::ClassParams = {
		&AMyProjectProjectile::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyProjectProjectile_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyProjectProjectile_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyProjectProjectile_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyProjectProjectile_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyProjectProjectile()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyProjectProjectile_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyProjectProjectile, 1324604389);
	template<> MYPROJECT_API UClass* StaticClass<AMyProjectProjectile>()
	{
		return AMyProjectProjectile::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyProjectProjectile(Z_Construct_UClass_AMyProjectProjectile, &AMyProjectProjectile::StaticClass, TEXT("/Script/MyProject"), TEXT("AMyProjectProjectile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyProjectProjectile);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
