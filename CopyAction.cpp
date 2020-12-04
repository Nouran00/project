#include "CopyAction.h"

#include "Grid.h"

CopyAction::CopyAction(ApplicationManager* pApp) : Action(pApp)
{
}

void CopyAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->ClearStatusBar();

}

void CopyAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	pOut->PrintMessage("Copy Card/Coins Set...Click on the cell");
	Cell clkCell(pIn->GetCellClicked());
	Cell* CCell = pGrid->GetCell(clkCell.GetCellPosition());
	if (CCell->HasCard())
	{
		Card* COPYcard = (Card*)(CCell->GetGameObject());
		pGrid->SetClipboard(COPYcard);
		pGrid->SetClipboardCS(NULL);
	}
	else if (CCell->HasCoinSet()) {
		CoinSet* COPYcoinset = (CoinSet*)(CCell->GetGameObject());
		pGrid->SetClipboardCS(COPYcoinset);
		pGrid->SetClipboard(NULL);
	}
	else
	{
		pGrid->PrintErrorMessage("Error You did not choose a Card/Coins Set...,Click to continue...");
		pIn->GetPointClicked(x, y);
	}
	pOut->ClearStatusBar();
}

CopyAction::~CopyAction()
{
}
