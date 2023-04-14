// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class BATTLEGAME_API UnitStateMachine
{
public:
	UnitStateMachine();

	class UnitState* GetCurrentState();
	void ChangeState(class UnitState* state);
	void Initialize(class UnitState* startState);
private:
	class UnitState* currentState;

};
