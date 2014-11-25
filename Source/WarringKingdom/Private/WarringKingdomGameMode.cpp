// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "WarringKingdom.h"
#include "WarringKingdomGameMode.h"
#include "WarringKingdomPlayerController.h"
#include "WarringKingdomCharacter.h"

AWarringKingdomGameMode::AWarringKingdomGameMode(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	// use our custom PlayerController class
	PlayerControllerClass = AWarringKingdomPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));

	//static ConstructorHelpers::FClassFinder<AGameMode> MainGameMode(TEXT("/Game/Blueprins/My"))

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}