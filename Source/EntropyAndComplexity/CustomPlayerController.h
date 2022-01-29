// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ENTROPYANDCOMPLEXITY_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	// Set up input bindings for this player controller
	virtual void SetupInputComponent() override;

	UPROPERTY()
	FTimerHandle InteractTimerHandle;

	UPROPERTY(BlueprintReadWrite)
	float InteractTimeout;
	
	UFUNCTION()
	void MoveForward(float Value);
	
	UFUNCTION()
	void MoveRight(float Value);
	
	UFUNCTION()
	void LookUp(float Value);
	
	UFUNCTION()
	void TurnAtRate(float Value);
	
	UFUNCTION()
	void LookUpAtRate(float Value);
	
	UFUNCTION()
	void Turn(float Value);

	UFUNCTION()
		void Jump();
	UFUNCTION()
		void JumpRelease();
	// UFUNCTION()
	// 	void Crouch();
	// UFUNCTION()
	// 	void EndCrouch();
	// UFUNCTION()
	// 	void Interact();
	// UFUNCTION()
	// 	void RunToggle();
	// UFUNCTION()
	// 	void Pickup();
	// UFUNCTION()
	// 	void Place();
};
