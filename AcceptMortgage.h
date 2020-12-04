#pragma once

#include "Action.h"
#include "OfferMortgage.h"

class AcceptMortgage : public Action
{

	// No parameters for this action

public:
	AcceptMortgage(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~AcceptMortgage();
};