// Fill out your copyright notice in the Description page of Project Settings.

#include "Coin.h"


// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent> ("Mesh");
	//Trigger = CreateDefaultSubobject<ATriggerVolume> ("Trigger");

	SetRootComponent (Mesh);
	//Trigger->SetupAttachment (Mesh);
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

