// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitStateWaiting.h"
#include "BaseUnit.h"
#include "UnitStateMachine.h"

UnitStateWaiting::UnitStateWaiting(ABaseUnit* unit, FString name)
{
	this->unit = unit;
	this->name = name;
}

UnitStateWaiting::~UnitStateWaiting()
{
}

void UnitStateWaiting::Enter()
{
	UE_LOG(LogTemp, Display, TEXT("Entered UnitStateWaiting"));
	i = 0;
}

void UnitStateWaiting::Exit()
{
	UE_LOG(LogTemp, Display, TEXT("Exit UnitStateWaiting"));
}

void UnitStateWaiting::LogicUpdate()
{
	if (++i > 400)
	{
		unit->GetStateMachine()->ChangeState((UnitState*)unit->stateDefault);
	}
}
