// Copyright OAXP Ltd.

#include "TankAIController.h"
#include "TankAimingComponent.h"
// Depends on movement component via pathfinding system



void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
		//Move to player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check radius is in cm

		//Aim towards Player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		//Fire if ready
		//TODO fix
		//ControlledTank->Fire(); //TODO don't fire every frame
}


