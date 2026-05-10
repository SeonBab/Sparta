// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PuzzleCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

struct FInputActionValue;

UCLASS()
class SPARTAPUZZLE_API APuzzleCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APuzzleCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// 입력 바인딩
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// 입력시 호출 될 함수
	// 캐릭터 이동
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	// 마우스를 통한 시점 회전
	UFUNCTION()
	void Look(const FInputActionValue& Value);
	// 캐릭터 점프
	UFUNCTION()
	void StartJump(const FInputActionValue& Value);
	UFUNCTION()
	void StopJump(const FInputActionValue& Value);

private:
	// 카메라 관련 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent> SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent> CameraComp;

	// 이동 기본 속도
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = true))
	float NormalMoveSpeed;
};
