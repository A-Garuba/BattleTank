// Alexander Garuba 2019.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
    auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
    auto ForceLocation = GetComponentLocation();
    auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
