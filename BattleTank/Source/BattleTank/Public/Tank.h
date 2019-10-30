// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BattleTank.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward Declarations
class UTankBarrel;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
    // Called by controller to delegate aiming to Aiming Component of controller's Tank
    void AimAt(FVector HitLocation);
    
    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UTankBarrel* BarrelToSet);
    
protected:
    UTankAimingComponent* TankAimingComponent = nullptr;
    
private:
    // Sets default values for this pawn's properties
    ATank();
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    UPROPERTY(EditAnywhere, Category = Firing)
    float LaunchSpeed = 100000; //1000 m/s in centimeters per second
};
