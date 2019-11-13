// Alexander Garuba 2019.

#pragma once

#include "BattleTank.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* BarrelToSet);
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetTurretReference(UTankTurret* TankToSet);
    
    UFUNCTION(BlueprintCallable, Category = Firing)
    void Fire();
    
    // Called by controller to delegate aiming to Aiming Component of controller's Tank
    void AimAt(FVector HitLocation);
    
protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:
    // Sets default values for this pawn's properties
    ATank();
    
    // Local barrel reference for spawning projectiles
    UTankBarrel* Barrel = nullptr;
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    TSubclassOf<AProjectile> ProjectileBlueprint;
    
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float LaunchSpeed = 4000; //40 m/s in centimeters per second
    
    UPROPERTY(EditDefaultsOnly, Category = Firing)
    float ReloadTimeInSeconds = 3;
    
    double LastFireTime = 0;
};
