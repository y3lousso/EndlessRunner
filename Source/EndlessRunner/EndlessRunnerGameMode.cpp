// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "EndlessRunnerGameMode.h"
#include "EndlessRunnerCharacter.h"


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

	straightInARow = 0;
}

// Called when the game starts or when spawned
void AEndlessRunnerGameMode::BeginPlay()
{
	Super::BeginPlay();
	AddFloorTile(BP_FloorTile_Basic, false, false);
	for (int i = 0; i < 5; i++) {
		AddFloorTile(BP_FloorTile_Basic, true, true);
	}
}

// Called every frame
void AEndlessRunnerGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEndlessRunnerGameMode::AddRandomFloorTile() {
	int floorType;
	if (straightInARow >= 2) {
		floorType = FMath::RandRange(0, 3);
		FString TheFloatStr = FString::SanitizeFloat((float)floorType);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, *TheFloatStr);
		}
	}
	else {
		floorType = FMath::RandRange(0, 1);
		straightInARow++;
	}
	switch (floorType)
	{
	case 0:
		AddFloorTile(BP_FloorTile_Basic, true, true);
		break;
	case 1:
		AddFloorTile(BP_FloorTile_Up, true, true);
		break;
	case 2:
		AddFloorTile(BP_FloorTile_Left, false, true);
		straightInARow = 0;
		break;
	case 3:
		AddFloorTile(BP_FloorTile_Right, false, true);
		straightInARow = 0;
		break;
	default:
		break;
	}

}


void AEndlessRunnerGameMode::AddFloorTile(TSubclassOf<AFloorTile> tileToSpawn, bool WithObstacle, bool WithGold)
{
	// Spawn a floor tile
	if (tileToSpawn != NULL) {
		UWorld* const World = GetWorld();
		if (World != NULL) {
			FActorSpawnParameters SpawnParam;
			SpawnParam.Owner = this;
			SpawnParam.Instigator = Instigator;
			AFloorTile* const currentFloorTile = World->SpawnActor<AFloorTile>(tileToSpawn, NextSpawnPoint, SpawnParam);
			// Update next spawn transform
			NextSpawnPoint = currentFloorTile->GetAttachTransform();

			// Add obstables to floor tile
			if (WithObstacle == true) {
				int nbBlocker = FMath::RandRange(0, 2);			
				currentFloorTile->AddBlockersToFloorTile(nbBlocker);								
			}

			// Add gold to floor tile
			if (WithObstacle == true) {
				int nbGold = FMath::RandRange(1, 2);
				currentFloorTile->AddGoldItemsToFloorTile(nbGold);
			}
		}
	}		
}



