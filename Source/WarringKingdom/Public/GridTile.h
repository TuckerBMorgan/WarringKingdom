// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GridTile.generated.h"

/**
 * 
 */
UCLASS()
class WARRINGKINGDOM_API AGridTile : public AActor
{
	GENERATED_UCLASS_BODY()

public:

	FString name;

	UPROPERTY(VisibleAnywhere, Category = Default)
		float h;


	UPROPERTY(VisibleAnywhere, Category = Default)
		float g;


	UPROPERTY(VisibleAnywhere, Category = Default)
		float f;

	UPROPERTY(VisibleAnywhere, Category = Default)
		bool HasBeenCheckFromSearch;

	UFUNCTION(BlueprintCallable, Category = Default)
		bool getHasBeenCheck();

	int x;

	int y;

	AGridTile* Parent;
	
};
