#include "AddSnakeAction.h"
#include"Input.h"
#include"Output.h"
#include"Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{

}

void AddSnakeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Snake: Click on it's Start Cell... ");
	startPos = pIn->GetCellClicked();

	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (!(startPos.IsValidCell()))
		pGrid->PrintErrorMessage("Invalid Cell Number");


	if (!(endPos.IsValidCell()))
		pGrid->PrintErrorMessage("Invalid Cell Number");

	if (startPos.HCell() != endPos.HCell())
		pGrid->PrintErrorMessage("End Cell and Start cell can not be in the same coloumn");

	if (endPos.GetCellNum() >= startPos.GetCellNum())
		pGrid->PrintErrorMessage("Start cell can not be smaller than End cell");

	for (int i = endPos.VCell(); i < startPos.VCell(); i++)
	{
		Cell oCell(i, endPos.VCell());
		if (oCell.HasSnake() || oCell.HasLadder())
		{
			pGrid->PrintErrorMessage("Two Snakes or Snake/Ladder can not overlap");
		}
	}
	Cell oCell(endPos);
	if (oCell.HasLadder() || oCell.HasSnake())
	{
		pGrid->PrintErrorMessage("End Or Start cell cannot be start of another ladder or snake");
	}
	Cell kCell(startPos);
	if (kCell.HasLadder() || kCell.HasSnake())
	{
		pGrid->PrintErrorMessage("End Or Start cell cannot be start of another ladder or snake");
	}

	pOut->ClearStatusBar();

}

void AddSnakeAction::Execute()
{
	ReadActionParameters();
	Snake* pSnake = new Snake(startPos, endPos);
	Grid* pGrid = pManager->GetGrid();
	bool added = pGrid->AddObjectToCell(pSnake);
	if (!added)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
}

AddSnakeAction::~AddSnakeAction()
{
}

