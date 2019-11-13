// Alexander Garuba 2019.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    
    //UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay() successful call"));
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
    
    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto ControlledTank = Cast<ATank>(GetPawn());
    if (PlayerTank)
    {
        // move towards player
        
        // aim towards player
        ControlledTank->AimAt(PlayerTank->GetActorLocation());
        
        // fire if ready
        ControlledTank->Fire(); // TODO limit firing rate
    }
}
