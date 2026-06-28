// GC_ItemEffectNotify.h
#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_Actor.h"
#include "GC_ItemEffectNotify.generated.h"

UCLASS()
class NBC_PROJECT_CHPATER3_API AGC_ItemEffectNotify : public AGameplayCueNotify_Actor
{
	GENERATED_BODY()

public:
	virtual void HandleGameplayCue(AActor* MyTarget, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters) override;

	// 블루프린트에서 UI 위젯 생성이나 텍스트를 띄우도록 구현
	UFUNCTION(BlueprintImplementableEvent, Category = "UI")
	void BroadcastUIEvent(const FString& Message);
	
	// 암전 해제 등 효과가 끝날 때 호출할 이벤트 추가
	UFUNCTION(BlueprintImplementableEvent, Category = "Effect")
	void OnEffectRemoved();
};