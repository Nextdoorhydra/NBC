// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameState.generated.h"

/**
 * 
 */
UCLASS()
class NBC_PROJECT_CHPATER3_API AMyGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AMyGameState();

	// 전역 점수를 저장하는 변수
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Score")
	int32 Score;

	// 현재 점수를 읽는 함수
	UFUNCTION(BlueprintPure, Category="Score")
	int32 GetScore() const;
	
	// 점수를 추가해주는 함수
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Score")
	void AddScore(int32 Amount);
};
