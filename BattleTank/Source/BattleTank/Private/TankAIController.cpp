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
    if (GetPlayerTank())
    {
        // move towards player
        
        // aim towards player
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
        
        // fire if ready
    }
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
