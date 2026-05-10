// Fill out your copyright notice in the Description page of Project Settings.


#include "NumberBaseballLib.h"

TArray<int32> UNumberBaseballLib::GenerateRandomNumbers()
{
	// 생성 될 수 있는 숫자 목록
	TArray<int32> AvailableNumbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	// 생성 된 숫자 저장
	TArray<int32> RandomNumberArr;

	// 3개의 랜덤한 숫자를 생성
	for (int32 i = 0; i < 3; ++i)
	{
		int32 Index = FMath::RandRange(0, AvailableNumbers.Num() - 1);
		RandomNumberArr.Add(AvailableNumbers[Index]);
		AvailableNumbers.RemoveAt(Index);
	}

	// 생성된 숫자 로그 출력
	for (auto e : RandomNumberArr)
	{
		UE_LOG(LogTemp, Log, TEXT("RandomeNumber: %d"), e);
	}

	return RandomNumberArr;
}

void UNumberBaseballLib::DecreaseRemainInputCount(int32& RemainInputCount)
{
	--RemainInputCount;
}

bool UNumberBaseballLib::IsGameCommand(const FString& Message)
{
	// 입력이 명령어를 입력한 것인지 확인
	bool bIsGameCommand = Message.Len() > 0 && Message[0] == '/';

	UE_LOG(LogTemp, Log, TEXT("IsGameCommand: %s"), (bIsGameCommand ? TEXT("True") : TEXT("False")));

	return bIsGameCommand;
}

FString UNumberBaseballLib::JudgeNumber(const TArray<int32>& RandomNumbers, const FString& Message, int32& Strikes, int32& Balls)
{
	// 입력된 문자열을 분리
	FString NumberPart = Message.Mid(1, 3);

	// 입력된 문자열을 숫자로 저장
	int32 Number = FCString::Atoi(*NumberPart);

	// 숫자를 자릿수 별로 분리 후 저장
	TArray<int32> InputNumber{ Number / 100, (Number / 10) % 10, Number % 10};

	// 잘못된 입력의 경우 아웃
	bool bIsOut = false;

	// 숫자 3개를 입력했는지 확인
	if (100 > Number || Number > 999)
	{
		UE_LOG(LogTemp, Log, TEXT("Input Error"));
		bIsOut = true;
	}
	// 중복된 숫자가 없는지 확인
	if (InputNumber[0] == InputNumber[1] || InputNumber[1] == InputNumber[2] || InputNumber[0] == InputNumber[2])
	{
		UE_LOG(LogTemp, Log, TEXT("Input Error"));
		bIsOut = true;
	}

	// 입력된 숫자 로그 출력
	for (auto e : InputNumber)
	{
		UE_LOG(LogTemp, Log, TEXT("InputNumber: %d"), e);
	}

	Strikes = 0, Balls = 0;
	FString Result;

	if (!bIsOut)
	{
		for (int32 i = 0; i < 3; ++i)
		{
			if (RandomNumbers[i] == InputNumber[i])
			{
				++Strikes;
			}
			else if (RandomNumbers.Contains(InputNumber[i]))
			{
				++Balls;
			}
		}

		if (Strikes > 0)
		{
			Result += TEXT("S") + FString::FromInt(Strikes);
		}
		if (Balls > 0)
		{
			Result += TEXT("B") + FString::FromInt(Balls);
		}
	}
	
	if (Strikes <= 0 && Balls <= 0 || bIsOut)
	{
		Result = TEXT("OUT");
	}

	// 스트라이크 로그 출력
	UE_LOG(LogTemp, Log, TEXT("Strikes: %d"), Strikes);
	// 볼 로그 출력
	UE_LOG(LogTemp, Log, TEXT("Balls: %d"), Balls);

	return Result;
}

bool UNumberBaseballLib::HasPlayerWon(const int32& Strikes, const int32& Balls)
{
	bool bIsPlayerWon = false;
	if (Strikes == 3)
	{
		// 승리
		bIsPlayerWon = true;
	}

	return bIsPlayerWon;
}