// Fill out your copyright notice in the Description page of Project Settings.


#include "LShipCharacter.h"

#include "LProjectileBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALShipCharacter::ALShipCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALShipCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALShipCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALShipCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

void ALShipCharacter::ShootProjectile()
{
	FVector GunLocation = GetMesh()->GetSocketLocation(GunSocketName);

	FVector TraceStart = GunLocation;
	FVector TraceEnd = TraceStart + (GetControlRotation().Vector() * 5000);

	FCollisionShape Shape;
	Shape.SetSphere(20.0f);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldStatic);
	ObjectQueryParams.AddObjectTypesToQuery(ECC_Pawn);

	FHitResult HitResult;

	if (GetWorld()->SweepSingleByObjectType(HitResult, TraceStart, TraceEnd, FQuat::Identity, ObjectQueryParams, Shape, Params))
	{
		// Overwrites trace end with impact point in world
		TraceEnd = HitResult.ImpactPoint;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Instigator = this;

	FRotator ProjRotation = FRotationMatrix::MakeFromX(TraceEnd - GunLocation).Rotator();

	FTransform SpawnTM = FTransform(ProjRotation, GunLocation);
	GetWorld()->SpawnActor<ALProjectileBase>(ProjectileActorClass, SpawnTM, SpawnParams);
}

