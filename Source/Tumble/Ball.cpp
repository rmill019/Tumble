// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"


// Sets default values
ABall::ABall()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent> ("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent> ("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent> ("Camera");

	RootComponent = Mesh;
	SpringArm->SetupAttachment (Mesh);
	Camera->SetupAttachment (SpringArm);

	Mesh->SetSimulatePhysics (true);
	movementSpeed = 100000;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Binding our Axis Inputs to PlayerInput
	InputComponent->BindAxis ("MoveForward", this, &ABall::MoveForward); // First Argument is how the Axis is named in Project Settings -> Input and last argument is name of Function with specifier
	InputComponent->BindAxis ("MoveLateral", this, &ABall::MoveLateral);

}

void ABall::MoveForward (float value)
{
	FVector ForceToAdd = FVector (1, 0, 0) * movementSpeed * value;
	Mesh->AddForce (ForceToAdd);
}

void ABall::MoveLateral (float value)
{
	FVector ForceToAdd = FVector (0, 1, 0) * movementSpeed * value;
	Mesh->AddForce (ForceToAdd);
}

