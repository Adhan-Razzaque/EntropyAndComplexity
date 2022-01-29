// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UENUM(BlueprintType)
enum class ECharacterActionStateEnum : uint8
{
	IDLE UMETA(DisplayName = "Idling"),
	MOVE UMETA(DisplayName = "Moving"),
	CROUCH UMETA(DisplayName = "Crouching"),
	JUMP UMETA(DisplayName = "Jumping"),
	PICKUP UMETA(DisplayName = "Picking Up"),
	PULLING UMETA(DiplayName = "Pulling")
};

UCLASS()
class ENTROPYANDCOMPLEXITY_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	// First person mesh (only seen by self)
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Base turn rate, in deg/sec
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	// Base look up/down rate, in deg/sec
	float BaseLookUpRate;

public:
	// Handles moving player forward/backward
	void MoveForward(float Val);

	// Handles moving player left/right
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	// Handles turning
	void Turn(float Val);

	//Handles looking up
	void LookUp(float Val);

	// Handles Jumping
	void HandleJump();

	// Handles Stop Jumping
	void HandleStopJump();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
};
