// Alexander Garuba 2019.

#pragma once

#include "BattleTank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    virtual void BeginPlay() override;
    
    virtual void Tick(float DeltaTime) override;
    
private:
    ATank* GetControlledTank() const;
    
    ATank* GetPlayerTank() const;
    
    // moves player's tank barrel towards aiming reticle
    void AimTowardsCrosshair();
    
    // return an OUT parameter, true if hits landscape
    bool GetSightRayHitLocation(FVector& OutHitLocation) const;
    
    // return an OUT parameter
    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    
    // return an OUT parameter, ray-trace along LookDirection
    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
    
    UPROPERTY(EditAnywhere)
    float CrosshairXLocation = .5;
    
    UPROPERTY(EditAnywhere)
    float CrosshairYLocation = .3333;
    
    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000; //10km in centimeters
};
