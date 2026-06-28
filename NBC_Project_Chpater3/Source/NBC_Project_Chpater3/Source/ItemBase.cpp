// ItemBase.cpp
#include "ItemBase.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"

AItemBase::AItemBase()
{
	PrimaryActorTick.bCanEverTick = false;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RootComponent = SphereComp;
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AItemBase::OnOverlapBegin);
}

void AItemBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (IAbilitySystemInterface* ASI = Cast<IAbilitySystemInterface>(OtherActor))
		{
			if (UAbilitySystemComponent* ASC = ASI->GetAbilitySystemComponent())
			{
				if (ItemEffect)
				{
					FGameplayEffectContextHandle ContextHandle = ASC->MakeEffectContext();
					ContextHandle.AddInstigator(this, this);
					ASC->ApplyGameplayEffectToSelf(ItemEffect.GetDefaultObject(), 1.0f, ContextHandle);
				}
			}
		}
		Destroy(); // 이펙트 적용 후 아이템 소멸
	}
}