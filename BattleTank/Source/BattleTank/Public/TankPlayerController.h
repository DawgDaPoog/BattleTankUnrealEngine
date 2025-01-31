// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 *  Responsible for helping the player aim.
 */
class UTankAimingComponent;
class ATank;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
private:
	UFUNCTION()
	void OnPossessedTankDeath();
	virtual void SetPawn(APawn* InPawn) override;
	bool GetLookVectorHitLocation(FHitResult& HitResult, FVector LookDirection) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairLocationX = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrosshairLocationY = 0.3333333333333;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;
protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);
	UFUNCTION(BlueprintPure, Category = "Referencing")
	ATank* GetOwningTank();
};
