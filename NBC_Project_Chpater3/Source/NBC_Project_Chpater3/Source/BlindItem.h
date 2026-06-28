// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "BlindItem.generated.h"

UCLASS()
class NBC_PROJECT_CHPATER3_API ABlindItem : public AItemBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABlindItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
