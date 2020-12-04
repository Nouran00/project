#include "Card12.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
Card12::Card12(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (9 here)

}
Card12::Card12()
{
	cardNumber = 12;
}
void Card12::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card12, Click to continue..");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

}
void Card12::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	Player* CurrentPlayer = pGrid->GetCurrentPlayer();
	pOut->PrintMessage("Choose the city you want to buy by writing its name (All capital letters) ");
	string actualmsg = pIn->GetSrting(pOut);
	pOut->PrintMessage("Click to continue");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	if (actualmsg == "CAIRO")
	{
		pOut->PrintMessage("Congratulations , You are now the owner of CAIRO , click to continue ");
		int x, y;
		pIn->GetPointClicked(x, y);
		Card* pCard = pGrid->GetTheFirstCard7();
		Card7* FirstCard7 = dynamic_cast <Card7*> (pCard);
		if (FirstCard7->Getownerplayer())
		{
			FirstCard7->SetOwnerPlayer(NULL);
		}

		pGrid->SetallCard7(CurrentPlayer);

	}
	if (actualmsg == "ALEX")
	{
		pOut->PrintMessage("Congratulations , You are now the owner of ALEX , click to continue ");
		Card* pCard = pGrid->GetTheFirstCard8();
		Card8* FirstCard8 = dynamic_cast <Card8*> (pCard);
		if (FirstCard8->Getownerplayer())
		{
			FirstCard8->SetOwnerPlayer(NULL);
		}

		pGrid->SetallCard8(CurrentPlayer);
	}
	if (actualmsg == "ASWAN")
	{
		pOut->PrintMessage("Congratulations , You are now the owner of ASWAN , click to continue ");
		Card* pCard = pGrid->GetTheFirstCard9();
		Card9* FirstCard9 = dynamic_cast <Card9*> (pCard);
		if (FirstCard9->Getownerplayer())
		{
			FirstCard9->SetOwnerPlayer(NULL);
		}

		pGrid->SetallCard9(CurrentPlayer);

	}
	if (actualmsg == "LUXOR")
	{
		pOut->PrintMessage("Congratulations , You are now the owner of LUXOR , click to continue ");
		Card* pCard = pGrid->GetTheFirstCard10();
		Card10* FirstCard10 = dynamic_cast <Card10*> (pCard);
		if (FirstCard10->Getownerplayer())
		{
			FirstCard10->SetOwnerPlayer(NULL);
		}

		pGrid->SetallCard10(CurrentPlayer);

	}
	if (actualmsg == "HURGHADA")
	{
		pOut->PrintMessage("Congratulations , You are now the owner of HURGHADA , click to continue ");
		Card* pCard = pGrid->GetTheFirstCard11();
		Card11* FirstCard11 = dynamic_cast <Card11*> (pCard);
		if (FirstCard11->Getownerplayer())
		{
			FirstCard11->SetOwnerPlayer(NULL);
		}

		pGrid->SetallCard11(CurrentPlayer);

	}
}
Card12::~Card12()
{}


