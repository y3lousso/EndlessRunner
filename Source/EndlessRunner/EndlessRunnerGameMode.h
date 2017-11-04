// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "GameFramework/GameModeBase.h"
#include "FloorTile.h"
#include "EndlessRunnerGameMode.generated.h"

UCLASS(minimalapi)
class AEndlessRunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEndlessRunnerGameMode();

	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = FloorTile)
	FTransform NextSpawnPoint;

	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = FloorTile)
	TSubclassOf<AFloorTile> floorTile;

protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Called for side to side input */
	void AddFloorTile();

};



