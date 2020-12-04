#pragma once


#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include "Action.h"


class InputDiceValue : public Action
{
public:
	InputDiceValue(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceValue();
};

