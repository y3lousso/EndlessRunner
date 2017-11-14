// Fill out your copyright notice in the Description page of Project Settings.

#include "GoldItem.h"


// Sets default values
AGoldItem::AGoldItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGoldItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoldItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

