#include "OfferMortgage.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"
#include "Card.h"
#include"Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "GameObject.h"

OfferMortgage::OfferMortgage(ApplicationManager* pApp) : Action(pApp)
{
	//Execute();
}

void OfferMortgage::ReadActionParameters()
{
	// no parameters to read from user
}


void OfferMortgage::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();                            //I added this (Nouran)                       

	//OfferMortgage* pOffer = new OfferMortgage;


	Player* pPlayer = pGrid->GetCurrentPlayer();                           //I added this (Nouran)

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card* card_7;
	Card* card_8;
	Card* card;
	Card7* card7;
	Card8* card8;
	Card9* card9;
	Card10* card10;
	Card11* card11;

	pOut->PrintMessage("Input the city that you want to mortgage: ");

	string CityToCell = pIn->GetSrting(pOut);

	if (CityToCell == "cairo" || CityToCell == "CAIRO" || CityToCell == "Cairo")
	{
		card_7 = pGrid->GetTheFirstCard7();
		card7 = dynamic_cast<Card7*>(card_7);
		
		if (card7) {
			if (card7->Getownerplayer() == pPlayer && card7->getmortgaged() == false)
			{
				pGrid->SetOfferMortgage(this);
				pOut->ClearStatusBar();
			}
			else
			{
				pGrid->SetOfferMortgage(NULL);
				//card7 = NULL;
				pOut->PrintMessage("You do not own this city. Click to continue... ");
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else if (CityToCell == "alex" || CityToCell == "Alex" || CityToCell == "ALEX")
	{
		card_8 = pGrid->GetTheFirstCard8();
        card8 = dynamic_cast<Card8*>(card_8);
		if (card_8) {
			
			if (card8->Getownerplayer() == pPlayer && card8->getmortgaged() == false)
			{
				pGrid->SetOfferMortgage(this);
				pOut->ClearStatusBar();
			}
			else
			{
				pGrid->SetOfferMortgage(NULL);
				pOut->PrintMessage("You do not own this city. Click to continue... ");
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else if (CityToCell == "aswan" || CityToCell == "Aswan" || CityToCell == "ASWAN")
	{
		card = pGrid->GetTheFirstCard9();
		card9 = dynamic_cast<Card9*>(card);
		if (card9) {
			if (card9->Getownerplayer()->getPlayerNum() == pPlayer->getPlayerNum() && card9->getmortgaged() == false)
			{
				pGrid->SetOfferMortgage(this);
				pOut->ClearStatusBar();
			}
			else
			{
				pGrid->SetOfferMortgage(NULL);
				pOut->PrintMessage("You do not own this city. Click to continue... ");
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else if (CityToCell == "luxor" || CityToCell == "Luxor" || CityToCell == "LUXOR")
	{
		card = pGrid->GetTheFirstCard10();
		card10 = dynamic_cast<Card10*>(card);
		if (card10) {
			if (card10->Getownerplayer() == pPlayer && card10->getmortgaged() == false)
			{
				pGrid->SetOfferMortgage(this);
				pOut->ClearStatusBar();
			}
			else
			{
				pGrid->SetOfferMortgage(NULL);
				pOut->PrintMessage("You do not own this city. Click to continue... ");
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else if (CityToCell == "hurghada" || CityToCell == "Hurghada" || CityToCell == "HURGHADA")
	{
		card = pGrid->GetTheFirstCard11();
		card11 = dynamic_cast<Card11*>(card);
		if (card11) {
			if (card11->Getownerplayer() == pPlayer && card11->getmortgaged() == false)
			{
				pGrid->SetOfferMortgage(this);
				pOut->ClearStatusBar();
			}
			else
			{
				pGrid->SetOfferMortgage(NULL);
				pOut->PrintMessage("You do not own this city. Click to continue... ");
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else
	{
		pOut->PrintMessage("This city does not exist. Click to continue... ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
}




OfferMortgage::~OfferMortgage()
{
}