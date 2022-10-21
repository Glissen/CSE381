// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef TEST_TestProjectile_generated_h
#error "TestProjectile.generated.h already included, missing '#pragma once' in TestProjectile.h"
#endif
#define TEST_TestProjectile_generated_h

#define Test_Source_Test_TestProjectile_h_14_SPARSE_DATA
#define Test_Source_Test_TestProjectile_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Test_Source_Test_TestProjectile_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define Test_Source_Test_TestProjectile_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATestProjectile(); \
	friend struct Z_Construct_UClass_ATestProjectile_Statics; \
public: \
	DECLARE_CLASS(ATestProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ATestProjectile)


#define Test_Source_Test_TestProjectile_h_14_INCLASS \
private: \
	static void StaticRegisterNativesATestProjectile(); \
	friend struct Z_Construct_UClass_ATestProjectile_Statics; \
public: \
	DECLARE_CLASS(ATestProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Test"), NO_API) \
	DECLARE_SERIALIZER(ATestProjectile)


#define Test_Source_Test_TestProjectile_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATestProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATestProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATestProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATestProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATestProjectile(ATestProjectile&&); \
	NO_API ATestProjectile(const ATestProjectile&); \
public:


#define Test_Source_Test_TestProjectile_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATestProjectile(ATestProjectile&&); \
	NO_API ATestProjectile(const ATestProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATestProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATestProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATestProjectile)


#define Test_Source_Test_TestProjectile_h_14_PRIVATE_PROPERTY_OFFSET
#define Test_Source_Test_TestProjectile_h_11_PROLOG
#define Test_Source_Test_TestProjectile_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_TestProjectile_h_14_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_TestProjectile_h_14_SPARSE_DATA \
	Test_Source_Test_TestProjectile_h_14_RPC_WRAPPERS \
	Test_Source_Test_TestProjectile_h_14_INCLASS \
	Test_Source_Test_TestProjectile_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Test_Source_Test_TestProjectile_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Test_Source_Test_TestProjectile_h_14_PRIVATE_PROPERTY_OFFSET \
	Test_Source_Test_TestProjectile_h_14_SPARSE_DATA \
	Test_Source_Test_TestProjectile_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Test_Source_Test_TestProjectile_h_14_INCLASS_NO_PURE_DECLS \
	Test_Source_Test_TestProjectile_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEST_API UClass* StaticClass<class ATestProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Test_Source_Test_TestProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
