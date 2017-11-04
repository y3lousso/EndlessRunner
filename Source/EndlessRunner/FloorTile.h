// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "FloorTile.generated.h"

UCLASS()
class ENDLESSRUNNER_API AFloorTile : public AActor
{
	GENERATED_BODY()
	
	/** Follow camera */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = FloorTile, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SceneComponent;

	/** Follow camera */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = FloorTile, meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* AttachPoint;

public:	
	// Sets default values for this actor's properties
	AFloorTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns ArrowComponent subobject **/
	FORCEINLINE struct FTransform GetAttachTransform() const { return AttachPoint->GetComponentTransform() ; }
	
};
