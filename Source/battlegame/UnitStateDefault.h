// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitState.h"

/**
 * 
 */
class BATTLEGAME_API UnitStateDefault : public UnitState
{
public:
	UnitStateDefault(class ABaseUnit* unit,FString name);

	virtual void Enter() override;
	virtual void Exit() override;
	virtual void LogicUpdate() override;
};
