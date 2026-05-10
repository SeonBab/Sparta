// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingActor.h"

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	Direction = FVector::One();

	if (bIsRandomSpeed)
	{
		MoveSpeed.X = FMath::RandRange(MinRandomSpeed.X, MaxRandomSpeed.X);
		MoveSpeed.Y = FMath::RandRange(MinRandomSpeed.Y, MaxRandomSpeed.Y);
		MoveSpeed.Z = FMath::RandRange(MinRandomSpeed.Z, MaxRandomSpeed.Z);
	}

	if (bIsRandomRange)
	{
		MaxMoveRange.X = FMath::RandRange(MinRandomMoveRange.X, MaxRandomMoveRange.X);
		MaxMoveRange.Y = FMath::RandRange(MinRandomMoveRange.Y, MaxRandomMoveRange.Y);
		MaxMoveRange.Z = FMath::RandRange(MinRandomMoveRange.Z, MaxRandomMoveRange.Z);
	}
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

void AMovingActor::Move(float DeltaTime)
{
	// 현재 위치 기반으로 시간에 비례해 이동할 위치를 구함
	FVector NewLocation = GetActorLocation();
	NewLocation += MoveSpeed * DeltaTime * Direction;

	// 최대 이동 범위를 벗어난다면 이동할 방향을 반대로 설정
	if (NewLocation.X > StartLocation.X + MaxMoveRange.X || NewLocation.X < StartLocation.X - MaxMoveRange.X)
	{
		// 새로운 위치가 최대 범위를 넘지 않도록 값 재설정
		NewLocation.X = StartLocation.X + MaxMoveRange.X * Direction.X;

		Direction.X *= -1;
	}
	if (NewLocation.Y > StartLocation.Y + MaxMoveRange.Y || NewLocation.Y < StartLocation.Y - MaxMoveRange.Y)
	{
		// 새로운 위치가 최대 범위를 넘지 않도록 값 재설정
		NewLocation.Y = StartLocation.Y + MaxMoveRange.Y * Direction.Y;

		Direction.Y *= -1;
	}
	if (NewLocation.Z > StartLocation.Z + MaxMoveRange.Z || NewLocation.Z < StartLocation.Z - MaxMoveRange.Z)
	{
		// 새로운 위치가 최대 범위를 넘지 않도록 값 재설정
		NewLocation.Z = StartLocation.Z + MaxMoveRange.Z * Direction.Z;

		Direction.Z *= -1;
	}

	// 위치 값 변경
	SetActorLocation(NewLocation);
}
