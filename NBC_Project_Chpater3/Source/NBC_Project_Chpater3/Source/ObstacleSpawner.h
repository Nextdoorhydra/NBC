#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleSpawner.generated.h"

UCLASS()
class NBC_PROJECT_CHPATER3_API AObstacleSpawner : public AActor
{
	GENERATED_BODY()

public:
	AObstacleSpawner();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TArray<TSubclassOf<class AObstacleBase>> ObstacleClasses;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	int32 SpawnCount = 10;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	FVector SpawnAreaRange = FVector(1500.f, 1500.f, 0.f);
};