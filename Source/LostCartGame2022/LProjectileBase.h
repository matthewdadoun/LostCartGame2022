// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LProjectileBase.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
UCLASS()
class LOSTCARTGAME2022_API ALProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALProjectileBase();

	// Sphere component used to detect projectile collision
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereComp;

	// Movement component for the projectile
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UProjectileMovementComponent* MovementComp;

	// The speed it has when it gets shot
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	float ShootSpeed;

	// 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UParticleSystemComponent* EffectComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* AudioComp;

	UFUNCTION()
	void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//virtual void BeginPlay() override;

protected:
	
	/* Plays the effects upon being destroyed */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Explode();

	// Impact effects that play upon 
	UPROPERTY(EditDefaultsOnly, Category = "Effects|Shake")
	UParticleSystem* ImpactVFX;

	UPROPERTY(EditDefaultsOnly, Category = "Effects|Shake")
	USoundBase* ImpactSound;

	UPROPERTY(EditDefaultsOnly, Category = "Effects|Shake")
	TSubclassOf<UCameraShakeBase> ImpactShake;

};
