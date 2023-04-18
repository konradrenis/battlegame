// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseUnit.generated.h"


UCLASS()
class BATTLEGAME_API ABaseUnit : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseUnit();
	

private:
	class UnitStateMachine* stateMachine;
	UPROPERTY(EditAnywhere)
	float movementSpeed;
	UPROPERTY(EditAnywhere)
	class UHealthComponent* HealthComponent;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere)
	class UCapsuleComponent* CapsuleCollider;

	static TArray<ABaseUnit*> instances;

public:
	class UnitStateDefault* stateDefault;
	class UnitStateWaiting* stateWaiting;

public:
	class UHealthComponent* GetHealthComponent();
	class UnitStateMachine* GetStateMachine();
	TArray<ABaseUnit*> GetInstances();

#pragma region UnrealCallbacks
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
#pragma endregion UnrealCallbacks
};
