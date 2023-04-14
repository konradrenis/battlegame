// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitStateDefault.h"
#include "BaseUnit.h"
#include "UnitStateMachine.h"

UnitStateDefault::UnitStateDefault(ABaseUnit* unit, FString name)
{
	this->unit = unit;
	this->name = name;
}

void UnitStateDefault::Enter()
{
	UE_LOG(LogTemp, Display, TEXT("Entered UnitStateDefault"));
	i = 0;
}

void UnitStateDefault::Exit()
{
	UE_LOG(LogTemp, Display, TEXT("Exit from UnitStateDefault"));
}

void UnitStateDefault::LogicUpdate()
{
	if (++i > 20)
	{
		unit->GetStateMachine()->ChangeState((UnitState*)unit->stateWaiting);
	}

}


