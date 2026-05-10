// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "FallingActor.generated.h"

class UBoxComponent;

UCLASS()
class SPARTAPUZZLE_API AFallingActor : public ABaseActor
{
	GENERATED_BODY()

public:
	AFallingActor();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	void ChageMaterial();

	void Falling();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision", meta = (AllowPrivateAccess = true))
	TObjectPtr<UBoxComponent> BoxCoollisionComp;

	// 타이머 핸들
	FTimerHandle MaterialTimerHandle;
	FTimerHandle FallingTimerHandle;

	// 떨어지는데 필요한 시간
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fall", meta = (AllowPrivateAccess = true))
	float FallingTime;

	// 떨어지기 전 변경 할 머티리얼
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Fall", meta = (AllowPrivateAccess = true))
	TObjectPtr<UMaterial> ChangeMaterial;
};
