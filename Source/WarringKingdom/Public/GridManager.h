// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GridManager.generated.h"



class AGridTile;

/**
 * 
 */
UCLASS()
class WARRINGKINGDOM_API AGridManager : public AActor
{
	GENERATED_UCLASS_BODY()

		TArray<AGridTile*> EightNeighorsOf(AGridTile* Center);

public:


	UPROPERTY(EditAnywhere, Category = Default)
		int32 SizeOfArray;

	UPROPERTY(EditAnywhere, Category = Default)
	TArray<AGridTile*> Grid;

	UPROPERTY(EditAnywhere, Category = Jimmy)
		AGridTile* A;

	UPROPERTY(EditAnywhere, Category = Jimmy)
		AGridTile* B;



	TArray<TArray<AGridTile*>> MainGrid;
	

	UPROPERTY(EditDefaultsOnly, Category = Default)
	TSubclassOf<class AGridTile> GridBluePrint;

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = Default)
	TArray<AGridTile*> FindPathToUnit(AGridTile* StartTile, AGridTile* EndTile);

	UFUNCTION(BlueprintCallable, Category = Default)
		AGridTile* GetA();

	UFUNCTION(BlueprintCallable, Category = Default)
		AGridTile* GetB();

	UFUNCTION(BlueprintCallable, Category = Default)
		TArray<AGridTile*> GetGrid();

	//UFUNCTION(BlueprintCallable, Category = Default)
	//	bool PlaceUnitInGrid;


	TArray<AGridTile*> LazyLoop;

	
};
