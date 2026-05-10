// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "PuzzlePlayerController.h"

APuzzleCharacter::APuzzleCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

	NormalMoveSpeed = 600.f;

	GetCharacterMovement()->MaxWalkSpeed = NormalMoveSpeed;
	GetCharacterMovement()->JumpZVelocity = 800.f;
	GetCharacterMovement()->AirControl = 0.5f;
}

void APuzzleCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APuzzleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuzzleCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInput)
	{
		APuzzlePlayerController* PlayerController = Cast<APuzzlePlayerController>(GetController());
		if (PlayerController)
		{
			// 입력 바인딩
			if (!PlayerController->MoveAction.IsNull())
			{
				EnhancedInput->BindAction(PlayerController->MoveAction.LoadSynchronous(), ETriggerEvent::Triggered, this, &APuzzleCharacter::Move);
			}

			if (!PlayerController->LookAction.IsNull())
			{
				EnhancedInput->BindAction(PlayerController->LookAction.LoadSynchronous(), ETriggerEvent::Triggered, this, &APuzzleCharacter::Look);
			}

			if (!PlayerController->JumpAction.IsNull())
			{
				EnhancedInput->BindAction(PlayerController->JumpAction.LoadSynchronous(), ETriggerEvent::Triggered, this, &APuzzleCharacter::StartJump);

				EnhancedInput->BindAction(PlayerController->JumpAction.LoadSynchronous(), ETriggerEvent::Completed, this, &APuzzleCharacter::StopJump);
			}
		}
	}
}

void APuzzleCharacter::Move(const FInputActionValue& Value)
{
	if (!Controller) return;

	const FVector2D MoveInput = Value.Get<FVector2D>();

	if (MoveInput.X != 0.f)
	{
		// X축 이동
		AddMovementInput(GetActorForwardVector(), MoveInput.X);
	}
	if (MoveInput.Y != 0.f)
	{
		// Y축 이동
		AddMovementInput(GetActorRightVector(), MoveInput.Y);
	}
}

void APuzzleCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookInput = Value.Get<FVector2D>();

	// 시점 X축 이동
	AddControllerYawInput(LookInput.X);
	// 시점 Y축 이동
	AddControllerPitchInput(LookInput.Y);
}

void APuzzleCharacter::StartJump(const FInputActionValue& Value)
{
	if (Value.Get<bool>())
	{
		Jump();
	}
}

void APuzzleCharacter::StopJump(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		StopJumping();
	}
}

