// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "HidingActor.generated.h"

/**
 * 
 */
UCLASS()
class SPARTAPUZZLE_API AHidingActor : public ABaseActor
{
	GENERATED_BODY()
	
public:
	AHidingActor();

protected:
	virtual void BeginPlay();

private:
	// 사라지도록 하는 함수
	void Hiding();

	// 나타나도록 하는 함수
	void Showing();

private:
	// 타이머 핸들
	FTimerHandle TimerHandle;

	// 사라지는데 필요한 시간
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotate", meta = (AllowPrivateAccess = true))
	float HidingTime;
	// 나타나는데 필요한 시간
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rotate", meta = (AllowPrivateAccess = true))
	float ShowingTime;
};
