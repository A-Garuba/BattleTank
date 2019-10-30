// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    
    //UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay() successful call"));
}

ATank* ATankAIController::GetControlledTank() const
{
    return  Cast<ATank>( GetPawn() );
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerTank  = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!PlayerTank) { return nullptr; }
    return Cast<ATank>( PlayerTank );
}