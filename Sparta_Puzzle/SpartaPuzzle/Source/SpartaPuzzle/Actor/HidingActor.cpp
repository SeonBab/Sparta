// Fill out your copyright notice in the Description page of Project Settings.


#include "HidingActor.h"

AHidingActor::AHidingActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHidingActor::BeginPlay()
{
	Super::BeginPlay();

	// 시작 시 사라지도록 하는 타이머 설정
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AHidingActor::Hiding, ShowingTime, false);
}

void AHidingActor::Hiding()
{
	// 타이머 핸들에 있는 타이머 설정 제거
	GetWorldTimerManager().ClearTimer(TimerHandle);

	if (!StaticMeshComp.IsNull())
	{
		// 사라짐
		StaticMeshComp->SetHiddenInGame(true);
	}

	// 보이도록 하는 타이머 설정
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AHidingActor::Showing, HidingTime, false);
}

void AHidingActor::Showing()
{
	// 타이머 핸들에 있는 타이머 설정 제거
	GetWorldTimerManager().ClearTimer(TimerHandle);

	if (!StaticMeshComp.IsNull())
	{
		// 나타남
		StaticMeshComp->SetHiddenInGame(false);
	}

	// 사라지도록 하는 타이머 설정
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AHidingActor::Hiding, ShowingTime, false);
}
