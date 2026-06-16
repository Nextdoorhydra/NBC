// Fill out your copyright notice in the Description page of Project Settings.

#include "DurationDestroyObstacle.h"

// Sets default values
ADurationDestroyObstacle::ADurationDestroyObstacle()
{   
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ADurationDestroyObstacle::BeginPlay()
{
	Super::BeginPlay();
    
	FTimerHandle DestroyTimerHandle;
	// 타이머는 언리얼 엔진이 자동 생성하는 wrapper 함수인 DestroyObstacle을 호출하도록 유지합니다.
	GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &ADurationDestroyObstacle::DestroyObstacle, 10.0f, false);
}

// BlueprintNativeEvent의 C++ 구현부는 함수명 뒤에 _Implementation을 붙여야 합니다.
void ADurationDestroyObstacle::DestroyObstacle_Implementation()
{
	Destroy();
}