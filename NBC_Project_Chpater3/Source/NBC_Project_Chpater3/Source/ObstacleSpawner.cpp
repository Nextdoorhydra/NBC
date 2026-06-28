#include "ObstacleSpawner.h"
#include "ItemSpawnRow.h"
#include "Obstacle/ObstacleBase.h"

AObstacleSpawner::AObstacleSpawner()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AObstacleSpawner::SpawnItems(int32 Count)
{
	if (!ItemDataTable) return;

	TArray<FItemSpawnRow*> SpawnRows;
	ItemDataTable->GetAllRows<FItemSpawnRow>(TEXT("SpawnItemsContext"), SpawnRows);

	if (SpawnRows.Num() == 0) return;

	float TotalChance = 0.f;
	for (FItemSpawnRow* Row : SpawnRows)
	{
		TotalChance += Row->SpawnChance;
	}

	for (int32 i = 0; i < Count; i++)
	{
		float RandomValue = FMath::FRandRange(0.f, TotalChance);
		float AccumulatedChance = 0.f;
		TSubclassOf<AActor> SelectedClass = nullptr;

		for (FItemSpawnRow* Row : SpawnRows)
		{
			AccumulatedChance += Row->SpawnChance;
			if (RandomValue <= AccumulatedChance)
			{
				SelectedClass = Row->ItemClass;
				break;
			}
		}

		if (SelectedClass)
		{
			FVector RandomLocation;
			RandomLocation.X = GetActorLocation().X + FMath::RandRange(-SpawnAreaRange.X, SpawnAreaRange.X);
			RandomLocation.Y = GetActorLocation().Y + FMath::RandRange(-SpawnAreaRange.Y, SpawnAreaRange.Y);
			RandomLocation.Z = GetActorLocation().Z;
			
			GetWorld()->SpawnActor<AActor>(SelectedClass, RandomLocation, FRotator::ZeroRotator);
		}
	}
}

void AObstacleSpawner::SpawnObstacles(int32 Count)
{
	if (ObstacleClasses.Num() > 0)
	{
		for (int32 i = 0; i < Count; i++)
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
