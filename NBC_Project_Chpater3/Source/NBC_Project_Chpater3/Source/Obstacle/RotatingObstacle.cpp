#include "RotatingObstacle.h"

ARotatingObstacle::ARotatingObstacle()
{
	PrimaryActorTick.bCanEverTick = true;	
}



void ARotatingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationRate * DeltaTime * RotationSpeed);
}

void ARotatingObstacle::BeginPlay()
{
	Super::BeginPlay();
	
	auto amount = FMath::RandRange(-180.f, 180.f);
	RotationRate = FRotator(0.f, amount, 0.f);
}
