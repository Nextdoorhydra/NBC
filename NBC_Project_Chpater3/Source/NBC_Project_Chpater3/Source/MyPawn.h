#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "MyPawn.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();	
	
	// 비행 및 부스터
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Flight")
	bool bIsFlightMode = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flight")
	float MaxBooster = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Flight")
	float CurrentBooster = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flight")
	float BoosterConsumeRate = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flight")
	float BoosterRegenRate = 30.f;


protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

private:
	// 컴포넌트
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComp;

	// IA
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction; // 기존 전/후/좌/우 유지

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveUpAction; // 신규: 상/하 이동용 (Axis1D)

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction; // 기존 Look 유지

	// 이동 및 물리 설정값
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 500.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationSpeed = 100.f;

	UPROPERTY(EditAnywhere, Category = "Physics")
	float Gravity = -980.f; 

	UPROPERTY(EditAnywhere, Category = "Physics")
	float AirControlMultiplier = 0.4f;
	// 상태 변수
	float ZVelocity = 0.f;
	bool bIsGrounded = false;

	// 입력 콜백 함수
	void Move(const FInputActionValue& Value);
	void MoveUp(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};