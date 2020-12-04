#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

    

	///TODO: Make the needed validations on the read parameters
	if (!(endPos.IsValidCell()))
	{
		pGrid->PrintErrorMessage("Invalid Cell...");
	}

	///TODO: Make the needed validations on the read parameters
	if (startPos.HCell() != endPos.HCell())
	{
		pGrid->PrintErrorMessage("end cell and start cell are not in the same column");
	}
	if (endPos.GetCellNum() <= startPos.GetCellNum())
	{
		pGrid->PrintErrorMessage("end cell cannot be smaller than start cell");
	}
	for (int i = startPos.VCell(); i < endPos.VCell(); i++)
	{
		Cell oCell(i, endPos.HCell());
		if (oCell.HasLadder())
		{
			pGrid->PrintErrorMessage("Two ladders cannot overlap");
		}
	}
	Cell oCell(endPos);
	if (oCell.HasLadder() || oCell.HasSnake())
	{
		pGrid->PrintErrorMessage("end cell cannot be start of another ladder or snake");
	}


	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
