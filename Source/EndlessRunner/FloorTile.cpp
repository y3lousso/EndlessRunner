// Fill out your copyright notice in the Description page of Project Settings.

#include "FloorTile.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
AFloorTile::AFloorTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	AttachPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("AttachPoint"));
	AttachPoint->SetupAttachment(SceneComponent);

	GoldItemBox = CreateDefaultSubobject<UBoxComponent>(TEXT("GoldItemBox"));
	GoldItemBox->SetupAttachment(SceneComponent);

	BlockerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BlockerBox"));
	BlockerBox->SetupAttachment(SceneComponent);

}

// Called when the game starts or when spawned
void AFloorTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloorTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloorTile::AddBlockersToFloorTile(int nbBlockers) {
	if (BP_Blocker != NULL) {
		UWorld* const World = GetWorld();
		if (World != NULL) {
			FActorSpawnParameters SpawnParam;
			SpawnParam.Owner = this;
			SpawnParam.Instigator = Instigator;
			for (int i = 0; i < nbBlockers; i++) {
				//Get a random point on the floor tile
				ABlocker* const currentBlocker = World->SpawnActor<ABlocker>(BP_Blocker, *(new FTransform(GetRandomPointInBoudingBox(BlockerBox))), SpawnParam);
				_blockers.Add(currentBlocker);
			}
		}
	}
}

void AFloorTile::AddGoldItemsToFloorTile(int nbGoldItems) {
	if (BP_GoldItem != NULL) {
		UWorld* const World = GetWorld();
		if (World != NULL) {
			FActorSpawnParameters SpawnParam;
			SpawnParam.Owner = this;
			SpawnParam.Instigator = Instigator;
			for (int i = 0; i < nbGoldItems; i++) {
				//Get a random point on the floor tile
				AGoldItem* const currentGoldItem = World->SpawnActor<AGoldItem>(BP_GoldItem, *(new FTransform(GetRandomPointInBoudingBox(GoldItemBox))), SpawnParam);
				_goldItems.Add(currentGoldItem);
			}
		}
	}
}

void AFloorTile::RemoveFloorTile() {
	//UE_LOG(LogTemp, Warning, TEXT("Your message : %s"), *_blockers->Num());
	for (int i = 0; i < _blockers.Num(); i++) {
		_blockers[i]->Destroy();
	}
	for (int i = 0; i < _goldItems.Num(); i++) {
		_goldItems[i]->Destroy();
	}
	Destroy();
}
