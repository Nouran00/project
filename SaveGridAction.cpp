#include "SaveGridAction.h"
#include"Action.h"
#include "Grid.h"
SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = Action::pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the name of the file to save into......");
	name = pIn->GetSrting(pOut);
	datasaved.open(name + ".txt", ios::out);
	LaddersNo = pGrid->Numofladders();
	SnakesNo = pGrid->Numofsnakes();
	CardsNo = pGrid->Numofcards();
	CoinSetsNo = pGrid->Numofcoinsset();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = Action::pManager->GetGrid();
	datasaved << LaddersNo << endl;
	pGrid->SaveAll(datasaved, ladder);
	datasaved << SnakesNo << endl;
	pGrid->SaveAll(datasaved, snake);
	datasaved << CardsNo << endl;
	pGrid->SaveAll(datasaved, card);
	datasaved << CoinSetsNo << endl;
	pGrid->SaveAll(datasaved, coinset);
	datasaved.close();
	pGrid->GetOutput()->PrintMessage("Data saved");

}