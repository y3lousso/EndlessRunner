// Fill out your copyright notice in the Description page of Project Settings.

#include "FloorTile.h"


// Sets default values
AFloorTile::AFloorTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	AttachPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("AttachPoint"));
	AttachPoint->SetupAttachment(SceneComponent);

	CoinBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CoinBox"));
	CoinBox->SetupAttachment(SceneComponent);

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

