// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
    /// Rotate barrel up and down based on RelativeSpeed
    RelativeSpeed = FMath::CLamp<float>(RelativeSpeed, -1, +1); //restrict speed [-1,1]
    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
    auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees); //restrict elevation (0,40)deg
    
    SetRelativeRotation( FRotator(Elevation,0,0) );
}