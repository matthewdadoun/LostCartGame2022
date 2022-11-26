// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LShipCharacter.h"
#include "LShipPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class LOSTCARTGAME2022_API ALShipPlayerCharacter : public ALShipCharacter
{
	GENERATED_BODY()


protected:
	UFUNCTION()
	void MoveRight(float Value);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
