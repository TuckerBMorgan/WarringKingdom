// Fill out your copyright notice in the Description page of Project Settings.

#include "WarringKingdom.h"
#include "GridManager.h"
#include "GridTile.h"
#include "Engine.h"

AGridManager::AGridManager(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{


}

AGridTile* AGridManager::GetA()
{
	return A;
}

AGridTile* AGridManager::GetB()
{
	return B;
}

TArray<AGridTile*> AGridManager::GetGrid()
{
	return LazyLoop;
}

void AGridManager::BeginPlay()
{

	for (int i = 0; i < SizeOfArray; i++)
	{
		MainGrid.Add(TArray<AGridTile*>()); 


	}

	for (int x = 0; x < SizeOfArray; x++)
	{
		for (int y = 0; y < SizeOfArray; y++)
		{
			MainGrid[x].Add(GetWorld()->SpawnActor<AGridTile>(GridBluePrint));
			MainGrid[x][y]->SetActorLocation(FVector((x * 400) - 1000, (y * 400) - 1000, 125), false);
			MainGrid[x][y]->name = FString::FromInt(x) + FString::FromInt(y);
			MainGrid[x][y]->x = x;
			MainGrid[x][y]->y = y;
			LazyLoop.Add(MainGrid[x][y]);
		}
		

	}

	A = MainGrid[0][0];
	B = MainGrid[4][4];



}


int FindLowest(TArray<AGridTile*> Ar)
{
	AGridTile* Lowest = Ar[0];
	int index = 0;


	for (int i = 0; i < Ar.Num(); i++)
	{
		if (Ar[i]->f < Lowest->f)
		{
			Lowest = Ar[i];
			index = i;
		}
	}




	return index;
}


TArray<AGridTile*> FinalPath(AGridTile* LastTile)
{
	TArray<AGridTile*> Path;

	AGridTile* Current = LastTile;

	while (Current != NULL)
	{
		Path.Add(Current);
		Current = Current->Parent;
	}
	return Path;
}


TArray<AGridTile*> AGridManager::FindPathToUnit(AGridTile* StartTile, AGridTile* EndTile)
{
	TArray<AGridTile*> OpenList;

	TArray<AGridTile*> CloseList;

	TMap<FString, AGridTile*> SeenTiles;

	for (int i = 0; i < SizeOfArray; i++)
	{
		for (int x = 0; x < SizeOfArray; x++)
		{
			MainGrid[i][x]->f = 0;
			if (MainGrid[i][x] == EndTile){
				print("FUCK YEcccAH");
			}
		}
	}

	int32 xDifToFinal_ = FMath::Abs(EndTile->x - StartTile->x);
	int32 yDifToFinal_ = FMath::Abs(EndTile->y - StartTile->y);
	int32 DsqrToFinal_ = FMath::Pow(xDifToFinal_, 2) + FMath::Pow(yDifToFinal_, 2);


	StartTile->h = DsqrToFinal_;
	StartTile->g = 0;
	StartTile->f = DsqrToFinal_;


	OpenList.Add(StartTile);

	while (OpenList.Num() > 0)
	{
	
		AGridTile* q = OpenList[FindLowest(OpenList)];
		if (q == EndTile)
		{
		//	q->Parent = CloseList[CloseList.Num() - 1];
		

			return FinalPath(q);
		}
		q->HasBeenCheckFromSearch = true;
		OpenList.Remove(q);
		CloseList.Add(q);
		SeenTiles.Add(q->name, q);
		TArray<AGridTile*> Neighbors = EightNeighorsOf(q);

		for (int i = 0; i < Neighbors.Num(); i++)
		{
		

			if (Neighbors[i] == EndTile)
			{
				Neighbors[i]->Parent = q;

				return FinalPath(Neighbors[i]);
			}

			
			if (CloseList.Contains(Neighbors[i]))
			{
				continue;
			}
			Neighbors[i]->Parent = q;


			int32 xDif = FMath::Abs(q->x - Neighbors[i]->x);
			int32 yDif = FMath::Abs(q->y - Neighbors[i]->y);
			int32 Dsqr = FMath::Pow(xDif, 2) + FMath::Pow(yDif, 2);
			int32 xDifToFinal = FMath::Abs(EndTile->x - Neighbors[i]->x);
			int32 yDifToFinal = FMath::Abs(EndTile->y - Neighbors[i]->y);
			int32 DsqrToFinal = FMath::Pow(xDifToFinal, 2) + FMath::Pow(yDifToFinal, 2);



			int tentativeG = q->g + Dsqr;
			if (Neighbors[i]->g == 0)
			{
				Neighbors[i]->g = tentativeG;
			}

			Neighbors[i]->h = DsqrToFinal;

			Neighbors[i]->f = Neighbors[i]->g + Neighbors[i]->h;

			
			if (!SeenTiles.Contains(Neighbors[i]->name))
			{
				OpenList.Add(Neighbors[i]);

			}

			if ((tentativeG <= Neighbors[i]->g))
			{
				Neighbors[i]->g = tentativeG;
				Neighbors[i]->f = Neighbors[i]->g + Neighbors[i]->h;

			}
		}
	}



	return TArray<AGridTile*>();
}



TArray<AGridTile*> AGridManager::EightNeighorsOf(AGridTile* Center)
{
	TArray<AGridTile*> Neigh;

	
	//Bellow
	if ((Center->y - 1) >= 0)
	{
		//Center
		Neigh.Add(MainGrid[Center->x][Center->y - 1]);

		//Left
		if ((Center->x - 1) >= 0)
		{
			Neigh.Add(MainGrid[Center->x - 1][Center->y - 1]);
			
		}
		//Right
		if ((Center->x + 1) < SizeOfArray)
		{
			Neigh.Add(MainGrid[Center->x + 1][Center->y - 1]);
		}
	}
	//Same level Left
	if ((Center->x - 1) >= 0)
	{
		Neigh.Add(MainGrid[Center->x - 1][Center->y]);
	}
	//Same Level Right
	if ((Center->x + 1)< SizeOfArray)
	{
		Neigh.Add(MainGrid[Center->x + 1][Center->y]);
	}



	//Above
	if ((Center->y + 1) < SizeOfArray)
	{
		//Center
		Neigh.Add(MainGrid[Center->x][Center->y + 1]);

		//Left
		if ((Center->x - 1) >= 0)
		{
			Neigh.Add(MainGrid[Center->x - 1][Center->y + 1]);
		}
		//Right
		if ((Center->x + 1) < SizeOfArray )
		{
			Neigh.Add(MainGrid[Center->x + 1][Center->y + 1]);
		}
	}



	
	


	return Neigh;

}



