#include "MyGameMode.h"
#include "MyCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "Source/MyPlayerController.h"
#include "Source/MyGameState.h"
#include "Source/ObstacleSpawner.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

AMyGameMode::AMyGameMode()
{
    PlayerControllerClass = AMyPlayerController::StaticClass();
    DefaultPawnClass = AMyCharacter::StaticClass();    
    GameStateClass = AMyGameState::StaticClass();
    
    CurrentWave = 0;
    TargetSpawnCount = 0;
    CachedObstacleSpawner = nullptr;
}

void AMyGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (ObstacleSpawnerClass)
    {
       CachedObstacleSpawner = GetWorld()->SpawnActor<AObstacleSpawner>(
          ObstacleSpawnerClass, 
          FVector::ZeroVector, 
          FRotator::ZeroRotator
       );
    }

    // 레벨 시작 시 1웨이브로 시작
    StartWave(1);
}

void AMyGameMode::StartWave(int32 WaveIndex)
{
    CurrentWave = WaveIndex;
    
    TargetSpawnCount = 20 * (1 << (CurrentWave - 1)); 

    FString WaveMessage = FString::Printf(TEXT("Wave %d 시작! (스폰 장애물: %d개)"), CurrentWave, TargetSpawnCount);
    if (GEngine)
    {
       GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, WaveMessage);
    }
    UE_LOG(LogTemp, Warning, TEXT("%s"), *WaveMessage);

    if (CachedObstacleSpawner)
    {
       CachedObstacleSpawner->SpawnObstacles(TargetSpawnCount);
       CachedObstacleSpawner->SpawnItems(5);
    }

    // GetWorldTimerManager().SetTimer(WaveTimerHandle, this, &AMyGameMode::OnWaveTimeUp, 30.0f, false);
}

// void AMyGameMode::OnWaveTimeUp()
// {
//     EndWave();
// }

void AMyGameMode::EndWave()
{
	// GetWorldTimerManager().ClearTimer(WaveTimerHandle);

    if (CurrentWave >= MaxWave)
    {
       FString ClearMessage = TEXT("모든 웨이브 클리어! 게임 종료!");
       if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, ClearMessage);
       UE_LOG(LogTemp, Warning, TEXT("%s"), *ClearMessage);
       
       OnWaveCompleted(true);
    }
    else
    {
       OnWaveCompleted(false);

       // 기존 플레이어 폰 파괴 및 재스폰
       APlayerController* PC = GetWorld()->GetFirstPlayerController();
       if (PC)
       {
           if (APawn* CurrentPawn = PC->GetPawn())
           {
               CurrentPawn->Destroy();
           }
                    
           RestartPlayer(PC);
       }
       
       // 다음 웨이브 시작 (이전 웨이브 장애물들은 맵에 유지된 상태로 추가 스폰됨)
       StartWave(CurrentWave + 1);
    }
}