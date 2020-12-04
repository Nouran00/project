#include "InputDiceValue.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
	//InputDiceValue::Execute();
}

void InputDiceValue::ReadActionParameters()
{
	// no parameters to read from user
/*	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Deleting Game Object,Click on the desired cell...");
	cellposition = pIn->GetCellClicked(); */
}



void InputDiceValue::Execute() {
	Grid* pGrid = pManager->GetGrid();                            //I added this (Nouran)                       

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action

	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	/*srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed
	*/
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Input dice value ");

	int diceNumber = pIn->GetInteger(pOut);
	// 3- Get the "current" player from pGrid
	Player* player = pGrid->GetCurrentPlayer();                           //I added this (Nouran)
	// 4- Move the currentPlayer using function Move of class player
	player->Move(pGrid, diceNumber);                                       //I added this (Nouran)
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();                                        //I added this (Nouran)

	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).

}

InputDiceValue::~InputDiceValue()
{
}
