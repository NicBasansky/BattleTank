// Copyright Nicholas Basansky 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTracks;


/**
 * Used to drive the tank tracks
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTracks* LeftTrackToSet, UTankTracks* RightTrackToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);

private:
	UTankTracks* LeftTrack = nullptr;
	UTankTracks* RightTrack = nullptr;

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

};
