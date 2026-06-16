#include "ObstacleSpawner.h"
#include "Obstacle/ObstacleBase.h"

AObstacleSpawner::AObstacleSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AObstacleSpawner::SpawnObstacles(int32 Count)
{
	if (ObstacleClass)
	{
		for (int32 i = 0; i < Count; i++)
		{
			FVector RandomLocation;
			RandomLocation.X = GetActorLocation().X + FMath::RandRange(-SpawnAreaRange.X, SpawnAreaRange.X);
			RandomLocation.Y = GetActorLocation().Y + FMath::RandRange(-SpawnAreaRange.Y, SpawnAreaRange.Y);
			RandomLocation.Z = GetActorLocation().Z;
			
			// Z축(Yaw) 랜덤 회전 적용
			float RandomYaw = FMath::FRandRange(0.0f, 360.0f);
			FRotator RandomRotation(0.0f, RandomYaw, 0.0f);
			
			GetWorld()->SpawnActor<AObstacleBase>(ObstacleClass, RandomLocation, RandomRotation);
		}
	}
}

void AObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}