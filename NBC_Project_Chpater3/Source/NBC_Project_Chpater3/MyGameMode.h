#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

class AObstacleSpawner;

UCLASS(minimalapi)
class AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameMode();

protected:
	virtual void BeginPlay() override;
    
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	TSubclassOf<AObstacleSpawner> ObstacleSpawnerClass;

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "GameLogic|Wave")
	void OnWaveCompleted(bool bIsGameClear);
    
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
	void StartWave(int32 WaveIndex);

	UFUNCTION(BlueprintCallable, Category = "GameLogic")
	void EndWave();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameLogic|Wave")
	int32 CurrentWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLogic|Wave")
	int32 MaxWave = 3;

private:
	UPROPERTY()
	AObstacleSpawner* CachedObstacleSpawner;

	int32 TargetSpawnCount;
	// FTimerHandle WaveTimerHandle; // 시간 제한 필요 시 구현
    
	// void OnWaveTimeUp();
};