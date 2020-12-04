#include "Card13.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"

Card13::Card13(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 13; // set the inherited cardNumber data member with the card number (13 here)
}

Card13::Card13()
{
	cardNumber = 13;
}

void Card13::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card13, Click to continue..");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Card13::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	Player* CurrentPlayer = pGrid->GetCurrentPlayer();
	int max = 0;
	Card* MaxCard = NULL;
	////////////////////////////////////////////////////////
	Card* pCard7 = pGrid->GetTheFirstCard7();
	if (pGrid->GetTheFirstCard7())
	{
		Card7* FirstCard7 = dynamic_cast <Card7*> (pCard7);
		if (FirstCard7->getprice() > max && FirstCard7->Getownerplayer() == CurrentPlayer)
		{
			max = FirstCard7->getprice();
			MaxCard = pCard7;
		}
	}
	///////////////////////////////////////////////////////
	Card* pCard8 = pGrid->GetTheFirstCard8();
	if (pGrid->GetTheFirstCard8())
	{
		Card8* FirstCard8 = dynamic_cast <Card8*> (pCard8);
		if (FirstCard8->getprice() > max && FirstCard8->Getownerplayer() == CurrentPlayer)
		{
			max = FirstCard8->getprice();
			MaxCard = pCard8;
		}
	}
	////////////////////////////////////////////////////////////
	Card* pCard9 = pGrid->GetTheFirstCard9();
	if (pGrid->GetTheFirstCard9())
	{
		Card9* FirstCard9 = dynamic_cast <Card9*> (pCard9);
		if (FirstCard9->getprice() > max && FirstCard9->Getownerplayer() == CurrentPlayer)
		{
			max = FirstCard9->getprice();
			MaxCard = pCard9;
		}
	}
	///////////////////////////////////////////////////////////////
	Card* pCard10 = pGrid->GetTheFirstCard10();
	if (pGrid->GetTheFirstCard10())
	{
		Card10* FirstCard10 = dynamic_cast <Card10*> (pCard10);
		if (FirstCard10->getprice() > max && FirstCard10->Getownerplayer() == CurrentPlayer)
		{
			max = FirstCard10->getprice();
			MaxCard = pCard10;
		}
	}
	//////////////////////////////////////////////////////////////////
	Card* pCard11 = pGrid->GetTheFirstCard11();
	if (pGrid->GetTheFirstCard11())
	{
		Card11* FirstCard11 = dynamic_cast <Card11*> (pCard11);
		if (FirstCard11->getprice() > max && FirstCard11->Getownerplayer() == CurrentPlayer)
		{
			max = FirstCard11->getprice();
			MaxCard = pCard11;
		}
	}
	/////////////////////////////////////////////////////////////////////
	if (MaxCard == NULL)
	{
		pOut->PrintMessage("You don't own any cities to lose , Click to continue .. ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}

	Card7* maxCard7 = dynamic_cast <Card7*> (MaxCard);
	Card8* maxCard8 = dynamic_cast <Card8*> (MaxCard);
	Card9* maxCard9 = dynamic_cast <Card9*> (MaxCard);
	Card10* maxCard10 = dynamic_cast <Card10*> (MaxCard);
	Card11* maxCard11 = dynamic_cast <Card11*> (MaxCard);
	//////////////////////////////////////////////////////////
	if (maxCard7 != NULL)
	{
		if (maxCard7->getmortgaged() == false)
		{
			pGrid->SetallCard7(NULL);
			pOut->PrintMessage("You have lost CAIRO , Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
		else
		{
			pGrid->SetallCard7(maxCard7->GetMortagePlayer());
			pOut->PrintMessage("You can't return CAIRO, the mortagage player owns it now ,Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	//////////////////////////////////////////////////////////////
	if (maxCard8 != NULL)
	{
		if (maxCard8->getmortgaged() == false)
		{
			pGrid->SetallCard8(NULL);
			pOut->PrintMessage("You have lost ALEX , Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
		else
		{
			pGrid->SetallCard8(maxCard8->GetMortagePlayer());
			pOut->PrintMessage("You can't return ALEX, the mortagage player owns it now ,Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	/////////////////////////////////////////////////////////////////////////
	if (maxCard9 != NULL)
	{
		if (maxCard9->getmortgaged() == false)
		{
			pGrid->SetallCard9(NULL);
			pOut->PrintMessage("You have lost ASWAN , Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
		else
		{
			pGrid->SetallCard9(maxCard9->GetMortagePlayer());
			pOut->PrintMessage("You can't return ASWAN, the mortagage player owns it now ,Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	////////////////////////////////////////////////////////////////////////
	if (maxCard10 != NULL)
	{
		if (maxCard10->getmortgaged() == false)
		{
			pGrid->SetallCard10(NULL);
			pOut->PrintMessage("You have lost LUXOR , Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
		else
		{
			pGrid->SetallCard10(maxCard10->GetMortagePlayer());
			pOut->PrintMessage("You can't return LUXOR, the mortagage player owns it now ,Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	///////////////////////////////////////////////////////////////////////
	if (maxCard11 != NULL)
	{
		if (maxCard11->getmortgaged() == false)
		{
			pGrid->SetallCard11(NULL);
			pOut->PrintMessage("You have lost HURGHADA , Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
		else
		{
			pGrid->SetallCard11(maxCard11->GetMortagePlayer());
			pOut->PrintMessage("You can't return HURGHADA, the mortagage player owns it now ,Click to continue .. ");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	/////////////////////////////////////////////////////////////////////
}

Card13::~Card13()
{}

