// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "MovingActor.generated.h"

UCLASS()
class SPARTAPUZZLE_API AMovingActor : public ABaseActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
private:
	// 이동 함수
	void Move(float DeltaTime);

private:
	// 시작 위치
	FVector StartLocation;
	// 이동할 방향
	FVector Direction;

	// 이동 속도
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MoveSpeed;
	// 최대 이동 범위
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MaxMoveRange;

	// 랜덤으로 값을 바꿀지
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	bool bIsRandomSpeed;
	// 랜덤으로 값을 바꿀 범위
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MinRandomSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MaxRandomSpeed;

	// 랜덤으로 값을 바꿀지
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	bool bIsRandomRange;
	// 랜덤으로 값을 바꿀 범위
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MinRandomMoveRange;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Move", meta = (AllowPrivateAccess = true))
	FVector MaxRandomMoveRange;
};
