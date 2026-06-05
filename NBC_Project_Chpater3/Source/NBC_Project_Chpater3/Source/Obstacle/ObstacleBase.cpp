#include "ObstacleBase.h"
#include "Components/StaticMeshComponent.h"

AObstacleBase::AObstacleBase()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

void AObstacleBase::BeginPlay()
{
	Super::BeginPlay();
}

void AObstacleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}