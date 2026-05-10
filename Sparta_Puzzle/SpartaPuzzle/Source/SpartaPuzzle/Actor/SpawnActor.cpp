// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnActor.h"
#include "BaseActor.h"

// Sets default values
ASpawnActor::ASpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (SpawnClass.Num() > 0)
	{
		int SpawnIndex = FMath::RandRange(0, SpawnClass.Num() - 1);
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		ABaseActor* SpawnActor = GetWorld()->SpawnActor<ABaseActor>(SpawnClass[SpawnIndex], GetActorTransform(), SpawnParams);
	}
}

// Called every frame
void ASpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

