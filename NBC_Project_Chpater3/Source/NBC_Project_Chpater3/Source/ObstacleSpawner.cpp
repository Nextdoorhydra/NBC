#include "ObstacleSpawner.h"
#include "Obstacle/ObstacleBase.h"

AObstacleSpawner::AObstacleSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	if (ObstacleClasses.Num() > 0)
	{
		for (int32 i = 0; i < SpawnCount; i++)
		{
			int32 RandomIndex = FMath::RandRange(0, ObstacleClasses.Num() - 1);
			TSubclassOf<AObstacleBase> SelectedClass = ObstacleClasses[RandomIndex];

			if (SelectedClass)
			{
				FVector RandomLocation;
				RandomLocation.X = GetActorLocation().X + FMath::RandRange(-SpawnAreaRange.X, SpawnAreaRange.X);
				RandomLocation.Y = GetActorLocation().Y + FMath::RandRange(-SpawnAreaRange.Y, SpawnAreaRange.Y);
				RandomLocation.Z = GetActorLocation().Z;
				
				GetWorld()->SpawnActor<AObstacleBase>(SelectedClass, RandomLocation, FRotator::ZeroRotator);
			}
		}
	}
}

void AObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}