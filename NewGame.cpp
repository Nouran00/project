#include "NewGame.h"

#include "Grid.h"
#include "Player.h"
#include "Action.h"

NewGame::NewGame(ApplicationManager* pApp) : Action(pApp)
{

}

void NewGame::ReadActionParameters()
{
	// no parameters to read from user
}
void NewGame::Execute()
{
	Grid* pGrid = pManager->GetGrid();


	Player* pPlayer;

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Do you want to start new game? click y for yes or n for no");
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
		pGrid->Reset();
	}
}
NewGame::~NewGame()
{

}