#pragma once
#include "Action.h"
#include "Grid.h"
#include <fstream>
class SaveGridAction : public Action
{
protected:
	ofstream datasaved;
	int LaddersNo;
	int SnakesNo;
	int CoinSetsNo;
	int CardsNo;
	string name;


public:
	SaveGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};