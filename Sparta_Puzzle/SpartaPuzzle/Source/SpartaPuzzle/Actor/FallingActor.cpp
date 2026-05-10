// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingActor.h"
#include "Components/BoxComponent.h"

AFallingActor::AFallingActor()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxCoollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxCoollisionComp->SetupAttachment(StaticMeshComp);
}

void AFallingActor::BeginPlay()
{
	Super::BeginPlay();

	// 오버랩 이벤트 델리게이트
	BoxCoollisionComp.Get()->OnComponentBeginOverlap.AddDynamic(this, &AFallingActor::OnComponentBeginOverlap);
}

void AFallingActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!GetWorldTimerManager().IsTimerActive(MaterialTimerHandle))
	{
		GetWorldTimerManager().SetTimer(MaterialTimerHandle, this, &AFallingActor::ChageMaterial, FallingTime * 0.5, false);
	}
	
	if (!GetWorldTimerManager().IsTimerActive(FallingTimerHandle))
	{
		GetWorldTimerManager().SetTimer(FallingTimerHandle, this, &AFallingActor::Falling, FallingTime, false);
	}
}

void AFallingActor::ChageMaterial()
{
	if (ChangeMaterial)
	{
		StaticMeshComp.Get()->SetMaterial(0, ChangeMaterial);
	}
}

void AFallingActor::Falling()
{
	StaticMeshComp->SetSimulatePhysics(true);
}
