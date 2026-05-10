// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PuzzlePlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class SPARTAPUZZLE_API APuzzlePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	// 입력 액션 및 매핑
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UInputMappingContext> InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input", meta = (AllowPrivateAccess = true))
	TSoftObjectPtr<UInputAction> JumpAction;
};
