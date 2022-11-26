// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "LShipCharacter.generated.h"

class ALProjectileBase;
UCLASS()
class LOSTCARTGAME2022_API ALShipCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALShipCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:

	// ActorClass to spawn projectile
	UPROPERTY(EditDefaultsOnly, Category = "ShipCharacter", BlueprintReadOnly)
	TSubclassOf<ALProjectileBase> ProjectileActorClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:

	// Shoot a projectile from the ship's gun
	UFUNCTION(BlueprintCallable)
	void ShootProjectile();

	// Socket for where the gun is 
	UPROPERTY(EditDefaultsOnly)
	FName GunSocketName;

};
