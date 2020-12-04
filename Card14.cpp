#include "Card14.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"

Card14::Card14(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 14; // set the inherited cardNumber data member with the card number (14 here)
}

Card14::Card14()
{
	cardNumber = 14;
}

void Card14::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card14, Click to continue..");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Card14::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	Player* CurrentPlayer = pGrid->GetCurrentPlayer();
	int min = INT_MAX;
	Card* MinCard = NULL;
	////////////////////////////////////////////////////////
	Card* pCard7 = pGrid->GetTheFirstCard7();
	if (pGrid->GetTheFirstCard7())
	{
		Card7* FirstCard7 = dynamic_cast <Card7*> (pCard7);
		if (FirstCard7->getprice() < min && FirstCard7->GetMortagePlayer() == CurrentPlayer)
		{
			min = FirstCard7->getprice();
			MinCard = pCard7;
		}
	}
	///////////////////////////////////////////////////////
	Card* pCard8 = pGrid->GetTheFirstCard8();
	if (pGrid->GetTheFirstCard8())
	{
		Card8* FirstCard8 = dynamic_cast <Card8*> (pCard8);
		if (FirstCard8->getprice() < min && FirstCard8->GetMortagePlayer() == CurrentPlayer)
		{
			min = FirstCard8->getprice();
			MinCard = pCard8;
		}
	}
	////////////////////////////////////////////////////////////
	Card* pCard9 = pGrid->GetTheFirstCard9();
	if (pGrid->GetTheFirstCard9())
	{
		Card9* FirstCard9 = dynamic_cast <Card9*> (pCard9);
		if (FirstCard9->getprice() < min && FirstCard9->GetMortagePlayer() == CurrentPlayer)
		{
			min = FirstCard9->getprice();
			MinCard = pCard9;
		}
	}
	///////////////////////////////////////////////////////////////
	Card* pCard10 = pGrid->GetTheFirstCard10();
	if (pGrid->GetTheFirstCard10())
	{
		Card10* FirstCard10 = dynamic_cast <Card10*> (pCard10);
		if (FirstCard10->getprice() < min && FirstCard10->GetMortagePlayer() == CurrentPlayer)
		{
			min = FirstCard10->getprice();
			MinCard = pCard10;
		}
	}
	//////////////////////////////////////////////////////////////////
	Card* pCard11 = pGrid->GetTheFirstCard11();
	if (pGrid->GetTheFirstCard11())
	{
		Card11* FirstCard11 = dynamic_cast <Card11*> (pCard11);
		if (FirstCard11->getprice() < min && FirstCard11->GetMortagePlayer() == CurrentPlayer)
		{
			min = FirstCard11->getprice();
			MinCard = pCard11;
		}
	}
	/////////////////////////////////////////////////////////////////////
	if (MinCard == NULL)
	{
		pOut->PrintMessage("You don't have any mortgaged cities to return , Click to continue .. ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}

	Card7* minCard7 = dynamic_cast <Card7*> (MinCard);
	Card8* minCard8 = dynamic_cast <Card8*> (MinCard);
	Card9* minCard9 = dynamic_cast <Card9*> (MinCard);
	Card10* minCard10 = dynamic_cast <Card10*> (MinCard);
	Card11* minCard11 = dynamic_cast <Card11*> (MinCard);
	//////////////////////////////////////////////////////////////////////
	if (minCard7 != NULL)
	{
		minCard7->setmortgaged(FALSE);
		minCard7->SetMortagePlayer(NULL);
		pGrid->SetallCard7(pGrid->getTherealownerofcard7());
		pOut->PrintMessage("You have returned CAIRO , Click to continue .. ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	if (minCard8 != NULL)
	{
		minCard8->setmortgaged(FALSE);
		minCard8->SetMortagePlayer(NULL);
		pGrid->SetallCard8(pGrid->getTherealownerofcard8());
		pOut->PrintMessage("You have returned ALEX , Click to continue .. ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	if (minCard9 != NULL)
	{
		minCard9->setmortgaged(FALSE);
		minCard9->SetMortagePlayer(NULL);
		pGrid->SetallCard9(pGrid->getTherealownerofcard9());
		pOut->PrintMessage("You have returned ASWAN , Click to continue .. ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	if (minCard10 != NULL)
	{
		minCard10->setmortgaged(FALSE);
		minCard10->SetMortagePlayer(NULL);
		pGrid->SetallCard10(pGrid->getTherealownerofcard10());
		pOut->PrintMessage("You have returned LUXOR , Click to continue .. ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	if (minCard11 != NULL)
	{
		minCard11->setmortgaged(FALSE);
		minCard11->SetMortagePlayer(NULL);
		pGrid->SetallCard11(pGrid->getTherealownerofcard11());
		pOut->PrintMessage("You have returned HURGHADA , Click to continue .. ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
}

Card14::~Card14()
{}
