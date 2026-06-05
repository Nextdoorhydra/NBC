#pragma once

#include "CoreMinimal.h"
#include "ObstacleBase.h"
#include "MovingObstacle.generated.h"

UCLASS()
class AMovingObstacle : public AObstacleBase
{
	GENERATED_BODY()
    
public:
	AMovingObstacle();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle|Settings")
	FVector MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle|Settings")
	float MaxRange;

private:
	FVector StartLocation;
};