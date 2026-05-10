// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "RotatingActor.generated.h"

/**
 * 
 */
UCLASS()
class SPARTAPUZZLE_API ARotatingActor : public ABaseActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	// 회전 함수
	void Rotate(float DeltaTime);

private:
	// 회전 속도
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotate", meta = (AllowPrivateAccess = true))
	FRotator RotateSpeed;

	// 랜덤으로 값을 바꿀지
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	bool bIsRandomSpeed;
	// 랜덤으로 값을 바꿀 범위
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FRotator MinRandomSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FRotator MaxRandomSpeed;
};
