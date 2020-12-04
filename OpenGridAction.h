#pragma once
#include"Action.h"
#include"SaveGridAction.h"
#include"Ladder.h"
#include"Snake.h"
#include"Card.h"
#include"CoinSet.h"

class OpenGridAction :public Action
{
	ifstream opendata;
	string name;
public:
	OpenGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};