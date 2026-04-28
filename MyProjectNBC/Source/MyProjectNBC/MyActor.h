// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECTNBC_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	int RandomMoveCount = 10;
	int MoveCount = 0;
	float TotalDistanceMoved = 0.0f;
	FTimerHandle MemberTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    void Move(FVector Direction);

	void Turn(FRotator Rotation);

	UFUNCTION()
	void TiggerCustomEvent();
};
