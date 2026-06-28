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

public:
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnItems(int32 Count);
	
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnObstacles(int32 Count);

protected:
protected:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	UDataTable* ItemDataTable;
	
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TArray<TSubclassOf<class AObstacleBase>> ObstacleClasses;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	int32 SpawnCount = 10;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	FVector SpawnAreaRange = FVector(1500.f, 1500.f, 0.f);
};