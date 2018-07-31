// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* L_TrackToSet, UTankTrack* R_TrackToSet)
{
	L_Track = L_TrackToSet;
	R_Track = R_TrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!L_Track || !R_Track) { return; }
	L_Track->SetThrottle(Throw);
	R_Track->SetThrottle(Throw);
	//Prevent souble speed
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call Super as we're replacing the function
	
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);

	IntendMoveForward(ForwardThrow);
	// UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, * MoveVelocityString);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!L_Track || !R_Track) { return; }
	L_Track->SetThrottle(Throw);
	R_Track->SetThrottle(-Throw);
	//Prevent souble speed
}