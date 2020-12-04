#pragma once
#include "Action.h"
class AddCoinsetAction :public Action
{
	CellPosition coinsetCP;
	int amount;
public:
	AddCoinsetAction(ApplicationManager* pApp); // A Constructor


	virtual void ReadActionParameters(); // Reads AddCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute();
};

