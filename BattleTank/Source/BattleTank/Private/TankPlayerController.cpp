// Alexander Garuba 2019.

#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    //UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay() successful call"));
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return  Cast<ATank>( GetPawn() );
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; } //protect nullptr
    
    FVector HitLocation; //OUT parameter
    if (GetSightRayHitLocation(HitLocation))
    {
        //UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
        GetControlledTank()->AimAt(HitLocation);
    }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    /// Find the crosshair position
    int32 ViewportSizeX, ViewportSizeY; //OUT parameters
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation,
                                    ViewportSizeY * CrosshairYLocation);
    
    /// "De-project" the screen position of the reticle to a world direction
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        /// Line-trace along LookDirection, and see where it hits (up to max range)
        GetLookVectorHitLocation(LookDirection, OutHitLocation);
    }
    
    return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
    FHitResult HitResult;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if (GetWorld()->LineTraceSingleByChannel(HitResult,
                                             StartLocation,
                                             EndLocation,
                                             ECollisionChannel::ECC_Visibility)
        )
    {
        OutHitLocation = HitResult.Location;
        return true;
    }
    else
    {
        OutHitLocation = FVector(0);
        return false; //line trace failed, probably pointing at sky
    }
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const
{
    FVector CameraWorldLocation;
    return DeprojectScreenPositionToWorld(ScreenLocation.X,
                                          ScreenLocation.Y,
                                          CameraWorldLocation,
                                          OutLookDirection);
}
