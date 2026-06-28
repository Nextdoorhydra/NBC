// GC_ItemEffectNotify.cpp
#include "GC_ItemEffectNotify.h"

void AGC_ItemEffectNotify::HandleGameplayCue(AActor* MyTarget, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters)
{

	if (EventType == EGameplayCueEvent::Executed || EventType == EGameplayCueEvent::OnActive)
	{
		BroadcastUIEvent(TEXT("방해 아이템 효과가 발동했습니다!"));
	}
	// GAS 효과(지속 시간)가 끝났을 때
	else if (EventType == EGameplayCueEvent::Removed) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Dfaengvijrengbvlijerwnbvljikerwnblrenbjlierw"));
		UE_LOG(LogTemp, Warning, TEXT("Dfaengvijrengbvlijerwnbvljikerwnblrenbjlierw"));
		UE_LOG(LogTemp, Warning, TEXT("Dfaengvijrengbvlijerwnbvljikerwnblrenbjlierw"));
		UE_LOG(LogTemp, Warning, TEXT("Dfaengvijrengbvlijerwnbvljikerwnblrenbjlierw"));
		UE_LOG(LogTemp, Warning, TEXT("Dfaengvijrengbvlijerwnbvljikerwnblrenbjlierw"));
		UE_LOG(LogTemp, Warning, TEXT("Dfaengvijrengbvlijerwnbvljikerwnblrenbjlierw"));
		UE_LOG(LogTemp, Warning, TEXT("Dfaengvijrengbvlijerwnbvljikerwnblrenbjlierw"));
		OnEffectRemoved();
	}
}