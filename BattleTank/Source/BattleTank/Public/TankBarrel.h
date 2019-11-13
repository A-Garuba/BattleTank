// Alexander Garuba 2019.

#pragma once

#include "BattleTank.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * TankBarrel allows the tank to aim upwards and downwards at a rate
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    // -1 is min, +1 is max
    void Elevate(float RelativeSpeed);
    
private:
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxDegreesPerSecond = 10;
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxElevationDegrees = 40;
    
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MinElevationDegrees = 0;
};
