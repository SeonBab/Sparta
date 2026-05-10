// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

void APuzzlePlayerController::BeginPlay()
{
    Super::BeginPlay();

    // 매핑 컨텍스트 추가
    ULocalPlayer* LocalPlayer = GetLocalPlayer();
    if (LocalPlayer)
    {
        UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
        if (Subsystem)
        {
            if (!InputMappingContext.IsNull())
            {

                Subsystem->AddMappingContext(InputMappingContext.LoadSynchronous(), 0);
            }
        }
    }
}
