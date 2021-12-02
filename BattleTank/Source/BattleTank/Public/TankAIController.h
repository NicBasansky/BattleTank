// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

protected:

	// How close the AI tank gets to the player
	UPROPERTY(EditAnywhere, Category = "Setup") // Consider EditDefaultsOnly
	float AcceptanceRadius = 80000;

private:

		virtual void BeginPlay() override;

		virtual void Tick(float DeltaTime) override;

		virtual void SetPawn(APawn* InPawn) override;

		UFUNCTION()
		void OnPossessedTankDeath();

};
