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
struct FHitResult;
struct FDamageEvent;
class AController;
struct FVector;
#ifdef MYPROJECT_MyProjectTrueWolfie_generated_h
#error "MyProjectTrueWolfie.generated.h already included, missing '#pragma once' in MyProjectTrueWolfie.h"
#endif
#define MYPROJECT_MyProjectTrueWolfie_generated_h

#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_SPARSE_DATA
#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin); \
	DECLARE_FUNCTION(execTakeDamage); \
	DECLARE_FUNCTION(execOnHit); \
	DECLARE_FUNCTION(execFire);


#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnOverlapBegin); \
	DECLARE_FUNCTION(execTakeDamage); \
	DECLARE_FUNCTION(execOnHit); \
	DECLARE_FUNCTION(execFire);


#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyProjectTrueWolfie(); \
	friend struct Z_Construct_UClass_AMyProjectTrueWolfie_Statics; \
public: \
	DECLARE_CLASS(AMyProjectTrueWolfie, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AMyProjectTrueWolfie)


#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAMyProjectTrueWolfie(); \
	friend struct Z_Construct_UClass_AMyProjectTrueWolfie_Statics; \
public: \
	DECLARE_CLASS(AMyProjectTrueWolfie, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), NO_API) \
	DECLARE_SERIALIZER(AMyProjectTrueWolfie)


#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyProjectTrueWolfie(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyProjectTrueWolfie) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyProjectTrueWolfie); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyProjectTrueWolfie); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyProjectTrueWolfie(AMyProjectTrueWolfie&&); \
	NO_API AMyProjectTrueWolfie(const AMyProjectTrueWolfie&); \
public:


#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyProjectTrueWolfie(AMyProjectTrueWolfie&&); \
	NO_API AMyProjectTrueWolfie(const AMyProjectTrueWolfie&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyProjectTrueWolfie); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyProjectTrueWolfie); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyProjectTrueWolfie)


#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_PRIVATE_PROPERTY_OFFSET
#define hw3_Source_MyProject_MyProjectTrueWolfie_h_10_PROLOG
#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_PRIVATE_PROPERTY_OFFSET \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_SPARSE_DATA \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_RPC_WRAPPERS \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_INCLASS \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define hw3_Source_MyProject_MyProjectTrueWolfie_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_PRIVATE_PROPERTY_OFFSET \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_SPARSE_DATA \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_INCLASS_NO_PURE_DECLS \
	hw3_Source_MyProject_MyProjectTrueWolfie_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MYPROJECT_API UClass* StaticClass<class AMyProjectTrueWolfie>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID hw3_Source_MyProject_MyProjectTrueWolfie_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
