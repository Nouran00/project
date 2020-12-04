#include "ApplicationManager.h"
#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "AddCoinsetAction.h"
#include"AddSnakeAction.h"	
#include "CopyAction.h"
#include "CutAction.h"
#include "PasteAction.h"
#include "DeleteGameObject.h"
#include "InputDiceValue.h"
#include "SellCity.h"
#include "OfferMortgage.h"
#include "AcceptMortgage.h"
#include"Returnmortgageaction.h"
#include "SwitchToDesignMode.h"
#include "SwitchToPlayMode.h"
#include "SaveGridAction.h"
#include "OpenGridAction.h"
#include "NewGame.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid* ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;
	case ADD_COIN_SET:
		pAct = new AddCoinsetAction(this);
		break;
	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;
	case COPY:
		pAct = new CopyAction(this);
		break;
	case CUT:
		pAct = new CutAction(this);
		break;
	case PASTE:
		pAct = new PasteAction(this);
		break;
	case SAVE_GRID:
		pAct = new SaveGridAction(this);
		break;
	case OPEN_GRID:
		pAct = new OpenGridAction(this);
		break;
	case EXIT:
		break;


	case TO_PLAY_MODE:
		pAct = new SwitchToPlayMode(this); ///TODO: temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		pAct = new SwitchToDesignMode(this);
		//TODO: temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case DELETE_OBJECT:
		pAct = new DeleteGameObject(this);
		break;

	case INPUT_DICE_VALUE:
		pAct = new InputDiceValue(this);
		break;

	case SELL_CITY:
		pAct = new SellCity(this);
		break;
	case OFFER_MORTGAGE:
		pAct = new OfferMortgage(this);
		break;
	case ACCEPT_MORTGAGE:
		pAct = new AcceptMortgage(this);
		break;
	case RETURN_MORTGAGE:
		pAct = new Returnmortgageaction(this);
		break;
	case NEW_GAME:
		pAct = new NewGame(this);
		break;


		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
