#pragma once

#include "Action.h"

class SellCity : public Action
{

	// No parameters for this action

public:
	SellCity(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~SellCity();
};
