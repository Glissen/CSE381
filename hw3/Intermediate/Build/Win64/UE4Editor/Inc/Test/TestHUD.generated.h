// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEST_TestHUD_generated_h
#error "TestHUD.generated.h already included, missing '#pragma once' in TestHUD.h"
#endif
#define TEST_TestHUD_generated_h

#define Test_Source_Test_TestHUD_h_16_SPARSE_DATA
#define Test_Source_Test_TestHUD_h_16_RPC_WRAPPERS
#define Test_Source_Test_TestHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define Test_Source_Test_TestHUD_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATestHUD(); \
	friend struct Z_Construct_UClass_ATestHUD_Statics; \
public: \
	DECLARE_CLASS(ATestHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ATestHUD)


#define Test_Source_Test_TestHUD_h_16_INCLASS \
private: \
	static void StaticRegisterNativesATestHUD(); \
	friend struct Z_Construct_UClass_ATestHUD_Statics; \
public: \
	DECLARE_CLASS(ATestHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ATestHUD)


#define Test_Source_Test_TestHUD_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATestHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATestHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATestHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATestHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATestHUD(ATestHUD&&); \
	NO_API ATestHUD(const ATestHUD&); \
public:


#define Test_Source_Test_TestHUD_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATestHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATestHUD(ATestHUD&&); \
	NO_API ATestHUD(const ATestHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATestHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATestHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATestHUD)


#define Test_Source_Test_TestHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CrosshairTexture() { return STRUCT_OFFSET(ATestHUD, CrosshairTexture); }


#define Test_Source_Test_TestHUD_h_13_PROLOG
#define Test_Source_Test_TestHUD_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_TestHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_TestHUD_h_16_SPARSE_DATA \
	Test_Source_Test_TestHUD_h_16_RPC_WRAPPERS \
	Test_Source_Test_TestHUD_h_16_INCLASS \
	Test_Source_Test_TestHUD_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Test_Source_Test_TestHUD_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_TestHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_TestHUD_h_16_SPARSE_DATA \
	Test_Source_Test_TestHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Test_Source_Test_TestHUD_h_16_INCLASS_NO_PURE_DECLS \
	Test_Source_Test_TestHUD_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class ATestHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Test_Source_Test_TestHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
