#include "Card15.h"
#include "Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"

Card15::Card15(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 15; // set the inherited cardNumber data member with the card number (15 here)
	numberofturns = 1;
}

Card15::Card15()
{
	cardNumber = 15;
	numberofturns = 1;
}

void Card15::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card15, Click to continue..");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pOut->PrintMessage("enter the number of turns for benefit switch..");
	numberofturns = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void Card15::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	int BoughtCities = 0;
	int counterofownedcities = 0;
	Player* CurrentPlayer = pGrid->GetCurrentPlayer();
	/////////////////////////////////////////////////////////////////////
	Card* pCard7 = pGrid->GetTheFirstCard7();
	if (pGrid->GetTheFirstCard7())
	{
		Card7* FirstCard7 = dynamic_cast <Card7*> (pCard7);
		if (FirstCard7->Getownerplayer())
		{
			if (CurrentPlayer == FirstCard7->Getownerplayer())
			{
				counterofownedcities++;
				FirstCard7->setChecktoReturnOwnership(false);
				string msg = "You are already the owner of CAIRO ";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
			else
			{
				BoughtCities++;
				FirstCard7->setChecktoReturnOwnership(true);
				Player* TheRealownerofcard7 = FirstCard7->Getownerplayer();
				FirstCard7->SetOwnerPlayer(NULL);
				pGrid->SetallCard7(CurrentPlayer);
				string msg = "You are now the owner of CAIRO for" + to_string(numberofturns) + "turns , Click to continue ..";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				FirstCard7->SetTempNonOwner(TheRealownerofcard7);
			}
		}
		else
		{
			pOut->PrintMessage("You won't get benefit from CAIRO as it has no owner , Click to continue ..");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	///////////////////////////////////////////////////////////////////////////
	Card* pCard8 = pGrid->GetTheFirstCard8();
	if (pGrid->GetTheFirstCard8())
	{
		Card8* FirstCard8 = dynamic_cast <Card8*> (pCard8);
		if (FirstCard8->Getownerplayer())
		{
			if (CurrentPlayer == FirstCard8->Getownerplayer())
			{
				counterofownedcities++;
				FirstCard8->setChecktoReturnOwnership(false);
				string msg = "You are already the owner of ALEX ";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
			else
			{
				BoughtCities++;
				FirstCard8->setChecktoReturnOwnership(true);
				Player* TheRealownerofcard8 = FirstCard8->Getownerplayer();
				FirstCard8->SetOwnerPlayer(NULL);
				pGrid->SetallCard8(CurrentPlayer);
				string msg = "You are now the owner of ALEX for" + to_string(numberofturns) + "turns , Click to continue ..";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				FirstCard8->SetTempNonOwner(TheRealownerofcard8);
			}
		}
		else
		{
			pOut->PrintMessage("You won't get benefit from ALEX as it has no owner , Click to continue ..");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	/////////////////////////////////////////////////////////////////////////
	Card* pCard9 = pGrid->GetTheFirstCard9();
	if (pGrid->GetTheFirstCard9())
	{
		BoughtCities++;
		Card9* FirstCard9 = dynamic_cast <Card9*> (pCard9);
		if (FirstCard9->Getownerplayer())
		{
			if (CurrentPlayer == FirstCard9->Getownerplayer())
			{
				counterofownedcities++;
				FirstCard9->setChecktoReturnOwnership(false);
				string msg = "You are already the owner of ASWAN ";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
			else
			{
				BoughtCities++;
				FirstCard9->setChecktoReturnOwnership(true);
				Player* TheRealownerofcard9 = FirstCard9->Getownerplayer();
				FirstCard9->SetOwnerPlayer(NULL);
				pGrid->SetallCard9(CurrentPlayer);
				string msg = "You are now the owner of ASWAN for" + to_string(numberofturns) + "turns , Click to continue ..";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				FirstCard9->SetTempNonOwner(TheRealownerofcard9);
			}
		}
		else
		{
			pOut->PrintMessage("You won't get benefit from ASWAN as it has no owner , Click to continue ..");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	Card* pCard10 = pGrid->GetTheFirstCard10();
	if (pGrid->GetTheFirstCard10())
	{
		Card10* FirstCard10 = dynamic_cast <Card10*> (pCard10);
		if (FirstCard10->Getownerplayer())
		{
			if (CurrentPlayer == FirstCard10->Getownerplayer())
			{
				counterofownedcities++;
				FirstCard10->setChecktoReturnOwnership(false);
				string msg = "You are already the owner of LUXOR ";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
			else
			{
				BoughtCities++;
				FirstCard10->setChecktoReturnOwnership(true);
				Player* TheRealownerofcard10 = FirstCard10->Getownerplayer();
				FirstCard10->SetOwnerPlayer(NULL);
				pGrid->SetallCard10(CurrentPlayer);
				string msg = "You are now the owner of LUXOR for" + to_string(numberofturns) + "turns , Click to continue ..";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				BoughtCities++;
				FirstCard10->SetTempNonOwner(TheRealownerofcard10);
			}
		}
		else
		{
			pOut->PrintMessage("You won't get benefit from LUXOR as it has no owner , Click to continue ..");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	//////////////////////////////////////////////////////////////////////
	Card* pCard11 = pGrid->GetTheFirstCard11();
	if (pGrid->GetTheFirstCard11())
	{
		Card11* FirstCard11 = dynamic_cast <Card11*> (pCard11);
		if (FirstCard11->Getownerplayer())
		{
			if (CurrentPlayer == FirstCard11->Getownerplayer())
			{
				counterofownedcities++;
				FirstCard11->setChecktoReturnOwnership(false);
				string msg = "You are already the owner of HURGHADA ";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
			else
			{
				BoughtCities++;
				FirstCard11->setChecktoReturnOwnership(true);
				Player* TheRealownerofcard11 = FirstCard11->Getownerplayer();
				FirstCard11->SetOwnerPlayer(NULL);
				pGrid->SetallCard11(CurrentPlayer);
				string msg = "You are now the owner of HURGHADA for" + to_string(numberofturns) + "turns , Click to continue ..";
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				BoughtCities++;
				FirstCard11->SetTempNonOwner(TheRealownerofcard11);
			}
		}
		else
		{
			pOut->PrintMessage("You won't get benefit from HURGHADA as it has no owner , Click to continue ..");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	////////////////////////////////////////////////////////////////////////
	if (BoughtCities == 0 && counterofownedcities == 0)
	{
		pOut->PrintMessage("You won't get benefit as there are no bought cities that you don't own , Click to continue ..");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		CurrentPlayer->setNumberOfBenefitSwitchTurns(0);
	}
	if (BoughtCities != 0)
	{
		CurrentPlayer->setNumberOfBenefitSwitchTurns(numberofturns);
	}

	//////////////////////////////////////////////////////////////////////
}
void Card15::Save(ofstream& OutFile, Type Type)
{
	if (Type == ObjectType)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << cardNumber << "\t" << temp.GetCellNum() << "\t" << numberofturns << "\t" << endl;

	}
	else { return; }

}
void Card15::Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end)
{
	if (Type == card)
	{

		int start, cardnum;
		Infile >> cardnum >> start >> numberofturns;
		cardNumber = cardnum;
		CellPosition temp(start);
		end.SetHCell(-1);
		end.SetVCell(-1);
		start1.SetHCell(temp.HCell());
		start1.SetVCell(temp.VCell());

	}
}

Card15::~Card15()
{}

