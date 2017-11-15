// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Core.h"
#include "Blocker.h"
#include "GoldItem.h"
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
	class UBoxComponent* GoldItemBox;

	TArray<ABlocker*> _blockers;
	TArray<AGoldItem*> _goldItems;

public:	
	// Sets default values for this actor's properties
	AFloorTile();

	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = Others)
	TSubclassOf<ABlocker> BP_Blocker;

	/** The floor tile to spawn */
	UPROPERTY(EditAnywhere, Category = Others)
	TSubclassOf<AGoldItem> BP_GoldItem;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	/** Called for side to side input */
	UFUNCTION(BlueprintCallable)
	void AddBlockersToFloorTile(int nbBlockers);

	/** Called for side to side input */
	UFUNCTION(BlueprintCallable)
	void AddGoldItemsToFloorTile(int nbGoldItems);

	/** Called for side to side input */
	UFUNCTION(BlueprintCallable)
	void RemoveFloorTile();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns ArrowComponent subobject **/
	FORCEINLINE struct FTransform GetAttachTransform() const { return AttachPoint->GetComponentTransform() ; }

	/** Returns ArrowComponent subobject **/
	FORCEINLINE struct FVector GetRandomPointInBoudingBox(UBoxComponent* box) const { return FMath::RandPointInBox(box->CalcBounds(GetTransform()).GetBox()); }

	
};
