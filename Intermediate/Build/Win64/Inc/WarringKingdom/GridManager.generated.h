// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef WARRINGKINGDOM_GridManager_generated_h
#error "GridManager.generated.h already included, missing '#pragma once' in GridManager.h"
#endif
#define WARRINGKINGDOM_GridManager_generated_h

#define AGridManager_EVENTPARMS
#define AGridManager_RPC_WRAPPERS \
	DECLARE_FUNCTION(execGetGrid) \
	{ \
		P_FINISH; \
		*(TArray<class AGridTile*>*)Result=this->GetGrid(); \
	} \
	DECLARE_FUNCTION(execGetB) \
	{ \
		P_FINISH; \
		*(class AGridTile**)Result=this->GetB(); \
	} \
	DECLARE_FUNCTION(execGetA) \
	{ \
		P_FINISH; \
		*(class AGridTile**)Result=this->GetA(); \
	} \
	DECLARE_FUNCTION(execFindPathToUnit) \
	{ \
		P_GET_OBJECT(AGridTile,StartTile); \
		P_GET_OBJECT(AGridTile,EndTile); \
		P_FINISH; \
		*(TArray<class AGridTile*>*)Result=this->FindPathToUnit(StartTile,EndTile); \
	}


#define AGridManager_CALLBACK_WRAPPERS
#define AGridManager_INCLASS \
	private: \
	static void StaticRegisterNativesAGridManager(); \
	friend WARRINGKINGDOM_API class UClass* Z_Construct_UClass_AGridManager(); \
	public: \
	DECLARE_CLASS(AGridManager, AActor, COMPILED_IN_FLAGS(0), 0, WarringKingdom, NO_API) \
	/** Standard constructor, called after all reflected properties have been initialized */    NO_API AGridManager(const class FPostConstructInitializeProperties& PCIP); \
	DECLARE_SERIALIZER(AGridManager) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME AGridManager


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
AGridManager_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
public: \
	AGridManager_RPC_WRAPPERS \
	AGridManager_CALLBACK_WRAPPERS \
	AGridManager_INCLASS \
public:


