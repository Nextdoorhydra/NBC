// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	FQuat OriginalQuat = FRotator(45.f, 45.f, 45.f).Quaternion();
	FRotator ConvertedRot = OriginalQuat.Rotator();
	FQuat ResultQuat = ConvertedRot.Quaternion();

	// 비트 단위 비교 시 false가 나올 확률이 매우 높음
	bool bIsSame = (OriginalQuat == ResultQuat); 
	UE_LOG(LogTemp, Warning, TEXT("Exactly Same? %s"), bIsSame ? TEXT("Yes") : TEXT("No"));
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

