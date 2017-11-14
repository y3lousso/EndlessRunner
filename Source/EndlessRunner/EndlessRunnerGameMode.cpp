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

// Called when the game starts or when spawned
void AEndlessRunnerGameMode::BeginPlay()
{
	Super::BeginPlay();
	AddStraightFloorTile(false);
	for (int i = 0; i < 5; i++) {
		AddStraightFloorTile(true);
	}
}

// Called every frame
void AEndlessRunnerGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}


void AEndlessRunnerGameMode::AddStraightFloorTile(bool WithObstacle)
{
	// Spawn a floor tile
	if (BP_FloorTile != NULL) {
		UWorld* const World = GetWorld();
		if (World != NULL) {
			FActorSpawnParameters SpawnParam;
			SpawnParam.Owner = this;
			SpawnParam.Instigator = Instigator;
			AFloorTile* const currentFloorTile = World->SpawnActor<AFloorTile>(BP_FloorTile, NextSpawnPoint, SpawnParam);
			UE_LOG(LogTemp, Warning, TEXT("Your message : %s"), *currentFloorTile->GetName());
			// Update next spawn transform
			NextSpawnPoint = currentFloorTile->GetAttachTransform();

			// Add obstables to floor tile
			if (WithObstacle == true && BP_Blocker != NULL) {
				int nbBlocker = FMath::RandRange(1, 2);
				for (int i = 0; i < nbBlocker; i++) {
					//Get a random point on the floor tile
					World->SpawnActor<ABlocker>(BP_Blocker, *(new FTransform(currentFloorTile->GetBlockerBoudingBox())), SpawnParam);
				}
			}
		}
	}	
	
}
