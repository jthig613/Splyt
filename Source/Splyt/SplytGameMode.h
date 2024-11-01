// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SplytGameMode.generated.h"

UENUM(BlueprintType)
enum class EDimensions : uint8
{
	DimensionOne UMETA(DisplayName = "VerseDimension"),
	DimensionTwo UMETA(DisplayName = "NuanceDimension")
};

//Create a delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDimensionSwapped, EDimensions, NewDimension);


UCLASS(minimalapi)
class ASplytGameMode : public AGameModeBase
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere, Category = "Rules", meta = (AllowPrivateAccess = true))
	EDimensions CurrentDimension;

public:
	ASplytGameMode();

	// Function to toggle the dimension
	UFUNCTION(BlueprintCallable, Category = "Dimension")
	void ToggleDimension();

	EDimensions GetDimension() { return CurrentDimension; }

	UPROPERTY(BlueprintAssignable, Category = "Dimension")
	FOnDimensionSwapped OnDimensionSwapped;

	
};



