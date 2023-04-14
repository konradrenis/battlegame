// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitStateMachine.h"
#include "UnitState.h"

UnitStateMachine::UnitStateMachine()
{
}


void UnitStateMachine::ChangeState(UnitState* state)
{
	currentState->Exit();
	currentState = state;
	currentState->Enter();
}

void UnitStateMachine::Initialize(UnitState* startState)
{
	currentState = startState;
	currentState->Enter();
}

UnitState* UnitStateMachine::GetCurrentState()
{
	return currentState;
}