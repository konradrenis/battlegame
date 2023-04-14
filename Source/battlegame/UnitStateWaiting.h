// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitState.h"

/**
 * 
 */
class BATTLEGAME_API UnitStateWaiting : public UnitState
{
public:
	UnitStateWaiting(class ABaseUnit* unit, FString name);
	~UnitStateWaiting();

	virtual void Enter() override;
	virtual void Exit() override;
	virtual void LogicUpdate() override;
};
