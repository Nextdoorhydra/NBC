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
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnObstacles(int32 Count);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class AObstacleBase> ObstacleClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	FVector SpawnAreaRange = FVector(1500.f, 1500.f, 0.f);
};