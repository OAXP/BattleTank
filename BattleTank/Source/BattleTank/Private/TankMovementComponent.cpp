// Copyright OAXP Ltd.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack* L_TrackToSet, UTankTrack* R_TrackToSet)
{
	L_Track = L_TrackToSet;
	R_Track = R_TrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call Super as we're replacing the function

	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);

	IntendTurnRight(RightThrow);
	IntendMoveForward(ForwardThrow);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(L_Track || !R_Track)) { return; }
	L_Track->SetThrottle(Throw);
	R_Track->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(L_Track || !R_Track)) { return; }
	L_Track->SetThrottle(Throw);
	R_Track->SetThrottle(-Throw);
}