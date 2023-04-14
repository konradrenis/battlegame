// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class BATTLEGAME_API UnitState
{
public:
	UnitState();
	virtual ~UnitState();
	
	virtual void Enter();
	virtual void Exit();
	virtual void LogicUpdate();
protected:
	FString name;
	class ABaseUnit* unit;
	int i;
};
