// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUnit.h"
#include "HealthComponent.h"
#include "Components/CapsuleComponent.h"
#include "UnitStateMachine.h"
#include "UnitState.h"
#include "UnitStateDefault.h"
#include "UnitStateWaiting.h"

// Sets default values
ABaseUnit::ABaseUnit()
{
	instances.Add(this);

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));

	CapsuleCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	CapsuleCollider->SetupAttachment(RootComponent);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(CapsuleCollider);
	

	

}

UHealthComponent* ABaseUnit::GetHealthComponent()
{
	return HealthComponent;
}

UnitStateMachine* ABaseUnit::GetStateMachine()
{
	return stateMachine;
}

TArray<ABaseUnit*> ABaseUnit::GetInstances()
{
	return instances;
}

// Called when the game starts or when spawned
void ABaseUnit::BeginPlay()
{
	Super::BeginPlay();
	stateMachine = new UnitStateMachine();

	stateDefault = new UnitStateDefault(this, "default");
	stateWaiting = new UnitStateWaiting(this, "waiting");

	stateMachine->Initialize(stateDefault);
}

// Called every frame
void ABaseUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	stateMachine->GetCurrentState()->LogicUpdate();

}

// Called to bind functionality to input
void ABaseUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

