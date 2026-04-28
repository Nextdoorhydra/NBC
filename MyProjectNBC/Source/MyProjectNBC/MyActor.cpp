// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Engine.h"
#include "Math/UnrealMathUtility.h"
#include "MyActor.h"

#pragma region util
static FVector GetRandomLocation()
{
    float x = FMath::RandRange(0.0f, 1000.0f);
    float y = FMath::RandRange(0.0f, 1000.0f);
    float z = FMath::RandRange(0.0f, 1000.0f);
    return FVector(x, y, z);
}

static FRotator GetRandomRotation()
{
    float x = FMath::RandRange(-180.0f, 180.0f);
    float y = FMath::RandRange(-180.0f, 180.0f);
    float z = FMath::RandRange(-180.0f, 180.0f);
    return FRotator(x, y, z);
}
#pragma endregion

AMyActor::AMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

}
 
void AMyActor::BeginPlay()
{
    Super::BeginPlay();
    SetActorLocation(FVector(0.0f, 0.0f, 50.0f));

    TiggerCustomEvent();
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyActor::TiggerCustomEvent()
{
    // RandomMoveCount == 0 이면 종료 + 최종 결과 출력
    if (RandomMoveCount <= 0) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
            FString::Printf(TEXT("MoveCount: %d, TotalDistanceMoved: %f"),
                MoveCount, TotalDistanceMoved));
        UE_LOG(LogTemp, Log, TEXT("MoveCount: %d, TotalDistanceMoved: %f"),
            MoveCount, TotalDistanceMoved);
        return;
    }

    // 50% 확률로 이동 & 회전
    if (FMath::RandRange(0, 1) == 0) {
        FVector nextDirection = GetRandomLocation();
        FRotator nextRotation = GetRandomRotation();

        Move(nextDirection);
        Turn(nextRotation);

        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
            FString::Printf(TEXT("(%d) Moved to: %s, Rotation: %s"),
                MoveCount, *nextDirection.ToString(), *nextRotation.ToString()));
        UE_LOG(LogTemp, Log, TEXT("(%d) Moved to: %s, Rotation: %s"),
            MoveCount, *nextDirection.ToString(), *nextRotation.ToString());
    }

    // 1초주기 실행
    RandomMoveCount--;

    FTimerHandle TempHandle;
    GetWorld()->GetTimerManager().SetTimer(TempHandle, this, &AMyActor::TiggerCustomEvent, 1.0f, false);
}


void AMyActor::Move(FVector Direction)
{
    MoveCount++;
    TotalDistanceMoved += FVector::Dist(GetActorLocation(), Direction);

    SetActorLocation(Direction);
}

void AMyActor::Turn(FRotator rotation)
{
    FRotator NewRotation = GetActorRotation() + rotation;
    SetActorRotation(NewRotation);
}
