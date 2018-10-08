// Copyright OAXP Ltd.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; //Forward Declaration
class UTankAimingComponent;
class ATankProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* TankAimingComponent = nullptr;


public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<ATankProjectile> ProjectileBlueprint;

	//TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 10000; //Find good default

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;

	UTankBarrel* Barrel = nullptr; //TODO remove

	double LastFireTime = 0;


	
	
};
