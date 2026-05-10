// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

UCLASS()
class SPARTAPUZZLE_API ABaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseActor();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	// 기본 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;
};
