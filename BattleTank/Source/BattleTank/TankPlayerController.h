// Copyright Nicholas Basansky 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"	//	Must be the last include

class UTankAimingComponent;

/**
* Responsible for helping the player aim.
*/

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

private:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// Start the tank moving the barrel so that a shot would it hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.00;

	//Return an OUT parameter, true if hits landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();
};
