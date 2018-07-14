// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "BattleTank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //Must be last

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	ATank* GetControlledTank() const;
	void AimTowardsCrosshair();
	
};
