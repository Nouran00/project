#include "SwitchToPlayMode.h"

#include "Grid.h"
#include "Player.h"
#include "Action.h"
#include "SaveGridAction.h"

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) : Action(pApp)
{

}

void SwitchToPlayMode::ReadActionParameters()
{
	// no parameters to read from user
}
void SwitchToPlayMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	//SaveGridAction* save = new SaveGridAction(this);
	pOut->PrintMessage("Do you want to save the grid before switching? click y for yes or n for no");
	string actualmsg = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	while (actualmsg != "y" && actualmsg != "n")
	{
		pOut->PrintMessage(" Please Re-enter y for Yes or n for No: ");
		actualmsg = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
	}
	if (actualmsg == "y")
	{
		pManager->ExecuteAction(SAVE_GRID);
	}
	pOut->CreatePlayModeToolBar();
}
SwitchToPlayMode::~SwitchToPlayMode()
{

}