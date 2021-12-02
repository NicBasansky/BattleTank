// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeRotationSpeed)
{
	// move the barrel the right amount this frame
	RelativeRotationSpeed = FMath::Clamp<float>(RelativeRotationSpeed, -1.0f, 1.0f);
	auto RotationChange = RelativeRotationSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
	//given a max elevation speed, and the frame time
}