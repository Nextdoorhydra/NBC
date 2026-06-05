#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NBC_Project_Chpater3GameMode.generated.h"

UCLASS(minimalapi)
class ANBC_Project_Chpater3GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANBC_Project_Chpater3GameMode();

protected:
	virtual void BeginPlay() override;

public:
	// 웨이브 시스템 관련 함수
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
	void StartWave(int32 WaveIndex);

	UFUNCTION(BlueprintCallable, Category = "GameLogic")
	void EndWave();

	// 현재 웨이브 정보
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameLogic|Wave")
	int32 CurrentWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameLogic|Wave")
	int32 MaxWave = 3;
};