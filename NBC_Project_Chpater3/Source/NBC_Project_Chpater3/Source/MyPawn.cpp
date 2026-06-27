#include "MyPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/World.h"

AMyPawn::AMyPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
    RootComponent = CapsuleComp;
    CapsuleComp->SetSimulatePhysics(false); 

    MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetupAttachment(RootComponent);
    MeshComp->SetSimulatePhysics(false);

    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
    SpringArmComp->SetupAttachment(RootComponent);
    SpringArmComp->bUsePawnControlRotation = false;

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
    CameraComp->SetupAttachment(SpringArmComp);
    
    ASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("ASC"));
    AttributeSet = CreateDefaultSubobject<UMyAttributeSet>(TEXT("AttributeSet"));
}

void AMyPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector Start = GetActorLocation();
    float CapsuleHalfHeight = CapsuleComp->GetScaledCapsuleHalfHeight();
    FVector End = Start + FVector(0.f, 0.f, -(CapsuleHalfHeight + 10.f));

    FHitResult HitResult;
    FCollisionQueryParams CollisionParams;
    CollisionParams.AddIgnoredActor(this); // 자기 자신 무시

    bIsGrounded = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams);

    // 부스터
    if (bIsFlightMode)
    {
        CurrentBooster -= BoosterConsumeRate * DeltaTime;
        if (CurrentBooster <= 0.f)
        {
            CurrentBooster = 0.f;
            bIsFlightMode = false;
        }
    }
    else if (bIsGrounded && CurrentBooster < MaxBooster)
    {
        CurrentBooster += BoosterRegenRate * DeltaTime;
        if (CurrentBooster > MaxBooster)
        {
            CurrentBooster = MaxBooster;
        }
    }

    // 비행모드가 아니면 중력
    if (!bIsFlightMode)
    {
        if (bIsGrounded && ZVelocity <= 0.f)
        {
            ZVelocity = 0.f;
        }
        else
        {
            ZVelocity += Gravity * DeltaTime;
            AddActorWorldOffset(FVector(0.f, 0.f, ZVelocity * DeltaTime), true);
        }
    }
    else
    {
        ZVelocity = 0.f; 
    }
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPawn::Move);
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyPawn::Look);
        
        if (MoveUpAction)
        {
            EnhancedInputComponent->BindAction(MoveUpAction, ETriggerEvent::Triggered, this, &AMyPawn::MoveUp);
        }
    }
}

void AMyPawn::Move(const FInputActionValue& Value)
{
    FVector2D MoveInput = Value.Get<FVector2D>();
    float DeltaTime = GetWorld()->GetDeltaSeconds();

    float CurrentSpeed = bIsGrounded ? MoveSpeed : MoveSpeed * AirControlMultiplier;
    
    FVector LocalMovement(MoveInput.Y, MoveInput.X, 0.f);
    AddActorLocalOffset(LocalMovement * CurrentSpeed * DeltaTime, true);
}

void AMyPawn::MoveUp(const FInputActionValue& Value)
{
    float MoveInput = Value.Get<float>();
    float DeltaTime = GetWorld()->GetDeltaSeconds();

    // 입력이 있고 부스터가 남아있다면 비행 모드 켜기
    if (FMath::Abs(MoveInput) > 0.1f && CurrentBooster > 0.f)
    {
        bIsFlightMode = true;
    }

    if (bIsFlightMode)
    {
        float CurrentSpeed = bIsGrounded ? MoveSpeed : MoveSpeed * AirControlMultiplier;
        FVector UpMovement(0.f, 0.f, MoveInput * CurrentSpeed * DeltaTime);
        AddActorLocalOffset(UpMovement, true);
    }
}

void AMyPawn::Look(const FInputActionValue& Value)
{
    FVector2D LookInput = Value.Get<FVector2D>();
    float DeltaTime = GetWorld()->GetDeltaSeconds();

    FRotator YawRot(0.f, LookInput.X * RotationSpeed * DeltaTime, 0.f);
    AddActorLocalRotation(YawRot);

    FRotator PitchRot(LookInput.Y * RotationSpeed * DeltaTime, 0.f, 0.f);
    SpringArmComp->AddLocalRotation(PitchRot);
}

void AMyPawn::SetMoveSpeed(float newSpeed)
{
    float changeSpeed = FMath::Clamp(newSpeed, 0.f, 500.f);
    MoveSpeed = changeSpeed;
}

UAbilitySystemComponent* AMyPawn::GetAbilitySystemComponent() const
{
    return ASC;
}

void AMyPawn::BeginPlay()
{
    Super::BeginPlay();  
        
    if (ASC && AttributeSet)
    {
        AttributeSet->InitMoveSpeed(MoveSpeed); 
    }
}

void AMyPawn::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    if (ASC)
    {
        ASC->InitAbilityActorInfo(this, this);
    }
}
