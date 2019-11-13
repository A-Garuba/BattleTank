// Alexander Garuba 2019.

#pragma once

#include "BattleTank.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * Tank Turret is used to rotate the barrel left and right at a rate
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
    GENERATED_BODY()
    
public:
    // -1 is min, +1 is max
    void Rotate(float RelativeSpeed);
    
private:
    UPROPERTY(EditDefaultsOnly, Category = Setup)
    float MaxDegreesPerSecond = 25;
};
