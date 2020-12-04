#include "AddCardAction.h"
#include"Card6.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "Card12.h"
#include "Card13.h"
#include "Card15.h"
#include "Input.h"
#include "Output.h"
#include "DecWalletCard_1.h"
#include "BackwardCard_3.h"
#include "NextCard_2.h"
#include "FireCard_5.h"
#include "PreventCard_4.h"

#include <iostream>
AddCardAction::AddCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Input* pIn = pManager->GetGrid()->GetInput();
	Output* pOut = pManager->GetGrid()->GetOutput();
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("please insert card number ");
	cardNumber = pIn->GetInteger(pOut);
	if (cardNumber < 1 || cardNumber>15)
	{
		pOut->PrintMessage("invalid card number ");
		return;
	}
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("please  select the cell needed to add card on it ");
	cardPosition = pIn->GetCellClicked();
	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
	pOut->ClearStatusBar();

}

void AddCardAction::Execute()
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();

	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card* pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new DecWalletCard_1(cardPosition);
		break;
	case 2:
		pCard = new NextCard_2(cardPosition);
		break;
	case 3:
		pCard = new BackwardCard_3(cardPosition);
		break;
	case 4:
		pCard = new PreventCard_4(cardPosition);
		break;
	case 5:
		pCard = new FireCard_5(cardPosition);
		break;

		// A- Add the remaining cases
	case 6:
		pCard = new Card6(cardPosition);
		break;
	case 7:
		pCard = new Card7(cardPosition);
		break;
	case 8:
		pCard = new Card8(cardPosition);
		break;
	case 9:
		pCard = new Card9(cardPosition);
		break;
	case 10:
		pCard = new Card10(cardPosition);
		break;
	case 11:
		pCard = new Card11(cardPosition);
		break;
	case 12:
		pCard = new Card12(cardPosition);
		break;
	case 13:
		pCard = new Card13(cardPosition);
		break;
	case 15:
		pCard = new Card15(cardPosition);
		break;
	}


	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)

	if (pCard)
	{
		int check = true;

		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pgrid = pManager->GetGrid();
		Output* pOut = pManager->GetGrid()->GetOutput();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pgrid);

		// C- Add the card object to the GameObject of its Cell:
		check = pgrid->AddObjectToCell(pCard);
	}
	// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar



	// A- We get a pointer to the Grid from the ApplicationManager

	// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type

	// C- Add the card object to the GameObject of its Cell:

	// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar



// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
