#pragma  once

#include "CoreMinimal.h"
#include "ItemSpawnRow.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class NBC_PROJECT_CHPATER3_API ASpawnVolume : public AActor
{
	GENERATED_BODY()

public:
	ASpawnVolume();
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawing")
	USceneComponent* Scene;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	UDataTable* ObjectDataTable;
	
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	FVector GetRandomPointInVolume() const;
	FItemSpawnRow* GetRandomItem() const;
	
	
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnItem(TSubclassOf<AActor> ActorClass);
};
