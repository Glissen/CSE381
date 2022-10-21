// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEST_TestGameModeBase_generated_h
#error "TestGameModeBase.generated.h already included, missing '#pragma once' in TestGameModeBase.h"
#endif
#define TEST_TestGameModeBase_generated_h

#define Test_Source_Test_TestGameModeBase_h_15_SPARSE_DATA
#define Test_Source_Test_TestGameModeBase_h_15_RPC_WRAPPERS
#define Test_Source_Test_TestGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define Test_Source_Test_TestGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATestGameModeBase(); \
	friend struct Z_Construct_UClass_ATestGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ATestGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ATestGameModeBase)


#define Test_Source_Test_TestGameModeBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesATestGameModeBase(); \
	friend struct Z_Construct_UClass_ATestGameModeBase_Statics; \
public: \
	DECLARE_CLASS(ATestGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ATestGameModeBase)


#define Test_Source_Test_TestGameModeBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATestGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATestGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATestGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATestGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATestGameModeBase(ATestGameModeBase&&); \
	NO_API ATestGameModeBase(const ATestGameModeBase&); \
public:


#define Test_Source_Test_TestGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATestGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATestGameModeBase(ATestGameModeBase&&); \
	NO_API ATestGameModeBase(const ATestGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATestGameModeBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATestGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATestGameModeBase)


#define Test_Source_Test_TestGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET
#define Test_Source_Test_TestGameModeBase_h_12_PROLOG
#define Test_Source_Test_TestGameModeBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_TestGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_TestGameModeBase_h_15_SPARSE_DATA \
	Test_Source_Test_TestGameModeBase_h_15_RPC_WRAPPERS \
	Test_Source_Test_TestGameModeBase_h_15_INCLASS \
	Test_Source_Test_TestGameModeBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Test_Source_Test_TestGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_TestGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_TestGameModeBase_h_15_SPARSE_DATA \
	Test_Source_Test_TestGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Test_Source_Test_TestGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	Test_Source_Test_TestGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class ATestGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Test_Source_Test_TestGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
