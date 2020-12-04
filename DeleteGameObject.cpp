#include "DeleteGameObject.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
DeleteGameObject::DeleteGameObject(ApplicationManager * pAM) :Action(pAM)
{
	DeleteGameObject::ReadActionParameters();
	DeleteGameObject::Execute();
}

void DeleteGameObject::ReadActionParameters()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Deleting Game Object,Click on the desired cell...");
	cellposition = pIn->GetCellClicked();
}

void DeleteGameObject::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(cellposition);
	pGrid->GetOutput()->PrintMessage("Object Deleted...");
	pGrid->UpdateInterface();
}

DeleteGameObject::~DeleteGameObject()
{
}