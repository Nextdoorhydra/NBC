// MyAttributeSet.cpp
#include "MyAttributeSet.h"
#include "../MyPawn.h"

void UMyAttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	Super::PostAttributeChange(Attribute, OldValue, NewValue);

	if (Attribute == GetMoveSpeedAttribute())
	{
		if (AMyPawn* AvatarCharacter = Cast<AMyPawn>(GetOwningActor()))
		{
			AvatarCharacter->SetMoveSpeed(NewValue);
		}
	}
}