// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYPROJECT_MyProjectHUD_generated_h
#error "MyProjectHUD.generated.h already included, missing '#pragma once' in MyProjectHUD.h"
#endif
#define MYPROJECT_MyProjectHUD_generated_h

#define hw3_Source_MyProject_MyProjectHUD_h_16_SPARSE_DATA
#define hw3_Source_MyProject_MyProjectHUD_h_16_RPC_WRAPPERS
#define hw3_Source_MyProject_MyProjectHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define hw3_Source_MyProject_MyProjectHUD_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyProjectHUD(); \
	friend struct Z_Construct_UClass_AMyProjectHUD_Statics; \
public: \
	DECLARE_CLASS(AMyProjectHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AMyProjectHUD)


#define hw3_Source_MyProject_MyProjectHUD_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAMyProjectHUD(); \
	friend struct Z_Construct_UClass_AMyProjectHUD_Statics; \
public: \
	DECLARE_CLASS(AMyProjectHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AMyProjectHUD)


#define hw3_Source_MyProject_MyProjectHUD_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyProjectHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyProjectHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyProjectHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyProjectHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyProjectHUD(AMyProjectHUD&&); \
	NO_API AMyProjectHUD(const AMyProjectHUD&); \
public:


#define hw3_Source_MyProject_MyProjectHUD_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyProjectHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyProjectHUD(AMyProjectHUD&&); \
	NO_API AMyProjectHUD(const AMyProjectHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyProjectHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyProjectHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyProjectHUD)


#define hw3_Source_MyProject_MyProjectHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CrosshairTexture() { return STRUCT_OFFSET(AMyProjectHUD, CrosshairTexture); }


#define hw3_Source_MyProject_MyProjectHUD_h_13_PROLOG
#define hw3_Source_MyProject_MyProjectHUD_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	hw3_Source_MyProject_MyProjectHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	hw3_Source_MyProject_MyProjectHUD_h_16_SPARSE_DATA \
	hw3_Source_MyProject_MyProjectHUD_h_16_RPC_WRAPPERS \
	hw3_Source_MyProject_MyProjectHUD_h_16_INCLASS \
	hw3_Source_MyProject_MyProjectHUD_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define hw3_Source_MyProject_MyProjectHUD_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	hw3_Source_MyProject_MyProjectHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	hw3_Source_MyProject_MyProjectHUD_h_16_SPARSE_DATA \
	hw3_Source_MyProject_MyProjectHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	hw3_Source_MyProject_MyProjectHUD_h_16_INCLASS_NO_PURE_DECLS \
	hw3_Source_MyProject_MyProjectHUD_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MYPROJECT_API UClass* StaticClass<class AMyProjectHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID hw3_Source_MyProject_MyProjectHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
