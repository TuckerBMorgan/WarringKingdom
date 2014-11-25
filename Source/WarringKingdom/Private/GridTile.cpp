// Fill out your copyright notice in the Description page of Project Settings.

#include "WarringKingdom.h"
#include "GridTile.h"


AGridTile::AGridTile(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	
}

bool AGridTile::getHasBeenCheck()
{
	return HasBeenCheckFromSearch;
}




