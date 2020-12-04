#pragma once

#include "Action.h"
#include"Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"

class OfferMortgage : public Action
{
public:


	// No parameters for this action

public:
	OfferMortgage(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~OfferMortgage();
};