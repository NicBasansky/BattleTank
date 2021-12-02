// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

class SprungWheel;

/**
 * TankTracks is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	//Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	//Max force per track per Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000; // Assume 40,000kg, and 1g accelleration

private:
	

	TArray<class ASprungWheel*> GetWheels() const;

	void DriveTrack(float CurrentThrottle);

};
