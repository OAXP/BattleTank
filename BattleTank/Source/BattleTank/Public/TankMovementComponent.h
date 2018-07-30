// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


class UTankTrack;
/**
 * Responsible from driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialise(UTankTrack* L_TrackToSet, UTankTrack* R_TrackToSet);
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float Throw);
	
private:
	UTankTrack * L_Track = nullptr;
	UTankTrack * R_Track = nullptr;
};
