// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

#include "PlayerCharacter.h"

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	InteractTimeout = 0.1;

	
	// Bind jump events
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACustomPlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACustomPlayerController::JumpRelease);

	// Bind movement events
	InputComponent->BindAxis("MoveForward", this, &ACustomPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACustomPlayerController::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &ACustomPlayerController::Turn);
	InputComponent->BindAxis("TurnRate", this, &ACustomPlayerController::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &ACustomPlayerController::LookUp);
	InputComponent->BindAxis("LookUpRate", this, &ACustomPlayerController::LookUpAtRate);
	
}

void ACustomPlayerController::MoveForward(float Value)
{
	APlayerCharacter* character = Cast<APlayerCharacter>(this->GetCharacter());
	if (character)
	{
		character->MoveForward(Value);
	}
}

void ACustomPlayerController::MoveRight(float Value)
{
	APlayerCharacter* character = Cast<APlayerCharacter>(this->GetCharacter());
	if (character)
	{
		character->MoveRight(Value);
	}
}

void ACustomPlayerController::LookUp(float Value)
{
	APlayerCharacter* character = Cast<APlayerCharacter>(this->GetCharacter());
	if (character)
	{
		character->LookUp(Value);
	}
}

void ACustomPlayerController::TurnAtRate(float Value)
{
	APlayerCharacter* character = Cast<APlayerCharacter>(this->GetCharacter());
	if (character)
	{
		character->TurnAtRate(Value);
	}
}

void ACustomPlayerController::LookUpAtRate(float Value)
{
	APlayerCharacter* character = Cast<APlayerCharacter>(this->GetCharacter());
	if (character)
	{
		character->LookUpAtRate(Value);
	}
}

void ACustomPlayerController::Turn(float Value)
{
	APlayerCharacter* character = Cast<APlayerCharacter>(this->GetCharacter());
	if (character)
	{
		character->Turn(Value);
	}
}

void ACustomPlayerController::Jump()
{
	APlayerCharacter* character = Cast<APlayerCharacter>(this->GetCharacter());
	if (character)
	{
		character->Jump();
	}
}

void ACustomPlayerController::JumpRelease()
{
	APlayerCharacter* character = Cast<APlayerCharacter>(this->GetCharacter());
	if (character)
	{
		character->StopJumping();
	}
}
