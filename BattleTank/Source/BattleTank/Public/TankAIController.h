// Alexander Garuba 2019.

#pragma once

#include "BattleTank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

// Forward Declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
    virtual void BeginPlay() override;
    
    virtual void Tick(float DeltaTime) override;
};
