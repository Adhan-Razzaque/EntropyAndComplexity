// Copyright Epic Games, Inc. All Rights Reserved.


#include "EntropyAndComplexityGameModeBase.h"

#include "CustomPlayerController.h"
#include "PlayerCharacter.h"

AEntropyAndComplexityGameModeBase::AEntropyAndComplexityGameModeBase() : Super()
{
	PlayerControllerClass = ACustomPlayerController::StaticClass();
	static ConstructorHelpers::FObjectFinder<UClass> pawnBPClass(TEXT("Class'/Game/Blueprints/PlayerCharacterBP.PlayerCharacterBP_C'"));

	if (pawnBPClass.Object) {

		// A2 Character
		UClass* pawnBP = (UClass*)pawnBPClass.Object;

		DefaultPawnClass = pawnBP;
	}
	else {
		// A2 Character
		DefaultPawnClass = APlayerCharacter::StaticClass();
	}
	
}

