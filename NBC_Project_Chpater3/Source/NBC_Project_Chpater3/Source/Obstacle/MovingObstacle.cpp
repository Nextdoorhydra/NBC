#include "MovingObstacle.h"

AMovingObstacle::AMovingObstacle()
{
	PrimaryActorTick.bCanEverTick = true;
		
	MaxRange = 500.f;
}

void AMovingObstacle::BeginPlay()
{
	Super::BeginPlay();
    
	auto amount = FMath::RandRange(-200.f, 200.f);
	MoveSpeed = FVector(amount, amount, 0.f);
	
	auto len = MoveSpeed.Length();
	auto determinant = 1000.f;
	
	if (len < determinant)
	{
		MoveSpeed *= determinant / len;
	}
		
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