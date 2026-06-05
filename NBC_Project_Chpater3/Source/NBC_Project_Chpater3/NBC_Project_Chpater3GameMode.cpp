#include "NBC_Project_Chpater3GameMode.h"
#include "NBC_Project_Chpater3Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"

ANBC_Project_Chpater3GameMode::ANBC_Project_Chpater3GameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
    
	CurrentWave = 0;
}

void ANBC_Project_Chpater3GameMode::BeginPlay()
{
	Super::BeginPlay();

	// 게임 시작 시 1번 웨이브 시작
	StartWave(1);
}

void ANBC_Project_Chpater3GameMode::StartWave(int32 WaveIndex)
{
	CurrentWave = WaveIndex;

	// 요구사항: 웨이브 시작 시 알림 출력
	FString WaveMessage = FString::Printf(TEXT("Wave %d 시작!"), CurrentWave);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, WaveMessage);
	}
	UE_LOG(LogTemp, Warning, TEXT("%s"), *WaveMessage);

	// TODO: SpawnVolume 배열을 순회하며 CurrentWave 난이도에 맞춰 아이템 스폰 횟수 및 타이머 설정 로직 추가
}

void ANBC_Project_Chpater3GameMode::EndWave()
{
	// TODO: 웨이브 종료 로직. 다음 웨이브로 넘어가거나, 3웨이브가 끝났다면 다음 레벨로 이동(OpenLevel)
}