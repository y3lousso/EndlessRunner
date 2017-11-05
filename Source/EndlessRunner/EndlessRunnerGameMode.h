// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "GameFramework/GameModeBase.h"
#include "FloorTile.h"
#include "Blocker.h"
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
	TSubclassOf<AFloorTile> BP_FloorTile;

	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = Others)
	TSubclassOf<ABlocker>  BP_Blocker;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Called for side to side input */
	UFUNCTION(BlueprintCallable)
	void AddFloorTile();

};



