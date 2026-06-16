#pragma once

#include "CoreMinimal.h"
#include "ObstacleBase.h"
#include "RotatingObstacle.generated.h"

UCLASS()
class ARotatingObstacle : public AObstacleBase
{
	GENERATED_BODY()
    
public:
	ARotatingObstacle();

public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle|Settings")
	float RotationSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle|Settings")
	FRotator RotationRate;
};