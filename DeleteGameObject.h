#pragma once
#include "Action.h"
class DeleteGameObject :public Action
{
private:
	CellPosition cellposition;
public:
	DeleteGameObject(ApplicationManager* pAM);
	virtual void ReadActionParameters();
	virtual void Execute();

	~DeleteGameObject();
};

