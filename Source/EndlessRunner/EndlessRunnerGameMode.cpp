// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "EndlessRunnerGameMode.h"
#include "EndlessRunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEndlessRunnerGameMode::AEndlessRunnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called every frame
void AEndlessRunnerGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddFloorTile();
}


void AEndlessRunnerGameMode::AddFloorTile() 
{
	// Spawn a floor tile
	if (floorTile != NULL) {
		UWorld* const World = GetWorld();
		if (World != NULL) {
			FActorSpawnParameters SpawnParam;
			SpawnParam.Owner = this;
			SpawnParam.Instigator = Instigator;
			AFloorTile* const floorTile2 = World->SpawnActor<AFloorTile>(floorTile, NextSpawnPoint, SpawnParam);
			UE_LOG(LogTemp, Warning, TEXT("Your message : %s"), *floorTile2->GetName());
			// Update next spawn transform
			NextSpawnPoint = floorTile2->GetAttachTransform();
		}
	}	
}
