// Alexander Garuba 2019.

#pragma once

#include "BattleTank.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set MAX driving force, applies forces to tank body
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    // Sets throttle value between -1 and +1
    UFUNCTION(BlueprintCallable, Category = Input)
    void SetThrottle(float Throttle);
    
    // Max force per track in Newtons
    UPROPERTY(EditDefaultsOnly)
    float TrackMaxDrivingForce = 40000000; // Assume 40 ton tank, 1g acceleration
};
