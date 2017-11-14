// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Core.h"
#include "FloorTile.generated.h"


UCLASS()
class ENDLESSRUNNER_API AFloorTile : public AActor
{
	GENERATED_BODY()
	
	/** Follow camera */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = FloorTile, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SceneComponent;

	/** Follow camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloorTile, meta = (AllowPrivateAccess = "true"))
	class UArrowComponent* AttachPoint;

	/** Blockerbox */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloorTile, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BlockerBox;

	/** Coinbox */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloorTile, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* CoinBox;

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

	/** Returns ArrowComponent subobject **/
	FORCEINLINE struct FVector GetBlockerBoudingBox() const { 
		FTransform* locatoworld = new FTransform();
		return FMath::RandPointInBox(BlockerBox->CalcBounds(*locatoworld).GetBox()); }

	/** Returns ArrowComponent subobject **/
	FORCEINLINE struct FVector GetCoinBoundingBox() const { 
		FTransform* locatoworld = new FTransform(); 
		return  FMath::RandPointInBox(CoinBox->CalcBounds(*locatoworld).GetBox());
	}

	/** Returns Random point on the tile **/
	//FORCEINLINE struct FVector GetRandomPointInBounds() const { return this->GetActorLocation() + FVector( FMath::FRandRange(-500, 500), FMath::FRandRange(-500, 500), 0);}
	
	
};
