// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstacleBase.h"
#include "DurationDestroyObstacle.generated.h"

UCLASS()
class NBC_PROJECT_CHPATER3_API ADurationDestroyObstacle : public AObstacleBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADurationDestroyObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent, Category = "Obstacle")
	void DestroyObstacle();
};