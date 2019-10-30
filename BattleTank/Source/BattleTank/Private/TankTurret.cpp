// Alexander Garuba 2019.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
    /// Rotate turret left and right based on RelativeSpeed
    RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1); //restrict speed [-1,1]
    auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    
    auto Rotation = RelativeRotation.Yaw + RotationChange;
    SetRelativeRotation( FRotator(0,Rotation,0) );
}
