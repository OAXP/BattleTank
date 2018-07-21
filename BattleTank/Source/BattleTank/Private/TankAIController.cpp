// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Tank possessed by AI"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {
		//Move to player


		//Aim towards Player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

