// Copyright Epic Games, Inc. All Rights Reserved.

#include "SplytGameMode.h"
#include "SplytCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASplytGameMode::ASplytGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	CurrentDimension = EDimensions::DimensionOne;
}

void ASplytGameMode::ToggleDimension()
{
	// Toggle between Dimension One and Dimension Two
	CurrentDimension = (CurrentDimension == EDimensions::DimensionOne) ? EDimensions::DimensionTwo : EDimensions::DimensionOne;

	// Log for debugging
	UE_LOG(LogTemp, Warning, TEXT("Dimension toggled to: %s"), CurrentDimension == EDimensions::DimensionOne ? TEXT("Dimension One") : TEXT("Dimension Two"));

	OnDimensionSwapped.Broadcast(CurrentDimension);
}

//void ASplytGameMode::DimensionToggle()
//{
//	if (CurrentDimension == EDimensions::DimensionTwo)
//	{
//		CurrentDimension = EDimensions::DimensionOne;
//	}
//	else
//	{
//		CurrentDimension = EDimensions::DimensionTwo;
//	}
//}

