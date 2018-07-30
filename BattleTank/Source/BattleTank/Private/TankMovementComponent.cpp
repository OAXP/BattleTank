// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* L_TrackToSet, UTankTrack* R_TrackToSet)
{
	if (!L_TrackToSet || !R_TrackToSet) { return; }
	L_Track = L_TrackToSet;
	R_Track = R_TrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward throw: %f"), Throw);
	L_Track->SetThrottle(Throw);
	R_Track->SetThrottle(Throw);
	//Prevent souble speed
}