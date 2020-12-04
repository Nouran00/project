#include "CutAction.h"
#include "Grid.h"


CutAction::CutAction(ApplicationManager* pApp) : Action(pApp)
{
}

CutAction::~CutAction()
{
}

void CutAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();


	pOut->ClearStatusBar();
}

void CutAction::Execute() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	pOut->PrintMessage("Cut Card/Coins Set... Click on the cell");
	Cell CardCell(pIn->GetCellClicked());
	Cell* CCell = pGrid->GetCell(CardCell.GetCellPosition());
	if (CCell->HasCard())
	{
		Card* CUTcard = (Card*)(CCell->GetGameObject());
		pGrid->SetClipboard(CUTcard);
		pGrid->SetClipboardCS(NULL);
	}
	else if (CCell->HasCoinSet()) {
		CoinSet* CUTcoinset = (CoinSet*)(CCell->GetGameObject());
		pGrid->SetClipboardCS(CUTcoinset);
		pGrid->SetClipboard(NULL);
	}
	else
	{
		pGrid->PrintErrorMessage("Error You did not choose a Card/Coins Set,Click to Continue...");
		pIn->GetPointClicked(x, y);
	}
	pGrid->RemoveObjectFromCell(CardCell.GetCellPosition());
	pOut->ClearStatusBar();
}
