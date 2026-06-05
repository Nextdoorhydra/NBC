#include "RotatingObstacle.h"

ARotatingObstacle::ARotatingObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

	RotationRate = FRotator(0.f, 90.f, 0.f);
}

void ARotatingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationRate * DeltaTime * RotationSpeed);
}