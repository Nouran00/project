#include "SwitchToDesignMode.h"

#include "Grid.h"
#include "Player.h"
#include "Action.h"

SwitchToDesignMode :: SwitchToDesignMode(ApplicationManager* pApp): Action(pApp)
{

}

void SwitchToDesignMode::ReadActionParameters()
{
	// no parameters to read from user
}
void SwitchToDesignMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();                          


	Player* pPlayer;

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pPlayer = pGrid->Check_Winner();
	if (pPlayer->GetstepCount() != 0) {
		pOut->PrintMessage(" The winner player is: " + to_string(pPlayer->getPlayerNum()) + " with wallet = " + to_string(pPlayer->GetWallet()) + " click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	else
	{
		pOut->PrintMessage(" There is no winner. Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	pGrid->Reset();
	pOut->CreateDesignModeToolBar();
}
SwitchToDesignMode ::~SwitchToDesignMode()
{

}