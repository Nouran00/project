#include "AddCoinSetAction.h"
#include"CoinSet.h"
#include "Input.h"
#include "Output.h" 


AddCoinsetAction::AddCoinsetAction(ApplicationManager* pApp) : Action(pApp) {
	amount = 0;
}
void AddCoinsetAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please click a cell:");
	coinsetCP = pIn->GetCellClicked();
	pOut->PrintMessage("Please enter the amount of coinset");
	amount = pIn->GetInteger(pOut);

	pOut->ClearStatusBar();

}

void AddCoinsetAction::Execute()
{
	bool added;
	ReadActionParameters();
	CoinSet* S = new CoinSet(coinsetCP);
	Grid* pGrid = pManager->GetGrid();
	if (amount < 0) {
		pGrid->PrintErrorMessage("Invalid amount!");
		return;
	}
	else 
	{
		
		S->SetAmount(amount);
		added = pGrid->AddObjectToCell(S);
	}
	if (added==false)
	{
		pGrid->PrintErrorMessage("cell already has gameobject");
	}

}