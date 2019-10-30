// Alexander Garuba 2019.

#pragma once

#include "BattleTank.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    // -1 is min, +1 is max
    void Elevate(float RelativeSpeed);
    
private:
    UPROPERTY(EditAnywhere, Category = Setup)
    float MaxDegreesPerSecond = 10;
    
    UPROPERTY(EditAnywhere, Category = Setup)
    float MaxElevationDegrees = 40;
    
    UPROPERTY(EditAnywhere, Category = Setup)
    float MinElevationDegrees = 0;
};
