// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NumberBaseballLib.generated.h"

/**
 * 
 */
UCLASS()
class NUMBERBASEBALL_API UNumberBaseballLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "NumberBaseball")
	static TArray<int32> GenerateRandomNumbers();

	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static void DecreaseRemainInputCount(int32& RemainInputCount);
	
	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static bool IsGameCommand(const FString& Message);

	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static FString JudgeNumber(const TArray<int32>& RandomNumbers, const FString& Message, int32& Strikes, int32& Balls);

	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static bool HasPlayerWon(const int32& Strikes, const int32& Balls);
};
