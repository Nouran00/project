#pragma once

#include "Action.h"

class Returnmortgageaction : public Action
{

	// No parameters for this action

public:
	Returnmortgageaction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~Returnmortgageaction();
};