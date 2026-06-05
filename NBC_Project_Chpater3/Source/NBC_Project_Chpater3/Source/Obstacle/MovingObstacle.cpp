#include "MovingObstacle.h"

AMovingObstacle::AMovingObstacle()
{
	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = FVector(200.f, 0.f, 0.f);
	MaxRange = 500.f;
}

void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();
    
	StartLocation = GetActorLocation();
}

void AMovingObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += MoveSpeed * DeltaTime;
	SetActorLocation(CurrentLocation);

	float DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);
	if (DistanceMoved >= MaxRange)
	{
		FVector MoveDirection = MoveSpeed.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MaxRange);
		MoveSpeed = -MoveSpeed; 
	}
}