#include "Card6.h"

Card6::Card6(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 6; // set the inherited cardNumber data member with the card number (6 here)
}

Card6::Card6()
{
	cardNumber = 6;
}

void Card6::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New Card6: Enter number of turns to be freezed");
	freezeCount = pIn->GetInteger(pOut);
	if (freezeCount < 1)
	{
		pOut->PrintMessage("New Card6: Re-Enter number of turns to be freezed");
		freezeCount = pIn->GetInteger(pOut);
	}
	pOut->PrintMessage("choose to freeze odd or even cells ");
	Evensodds = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void Card6::Apply(Grid* pGrid, Player* CurrentPlayer)
{
	Card::Apply(pGrid, CurrentPlayer);
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int counter = 0;
	if (Evensodds == 1)
	{
		for (int i = 0; i < MaxPlayerCount - 1; i++)
		{
			pGrid->AdvanceCurrentPlayer();
			Player* otherPlayer = pGrid->GetCurrentPlayer();
			CellPosition otherpos = (otherPlayer->GetCell()->GetCellPosition());
			if (otherpos.GetCellNum() % 2 != 0)
			{
				otherPlayer->setFreezeCount(freezeCount);
				otherPlayer->setOorEPrevented(1);
				counter++;
			}
		}
	}
	if (Evensodds == 0)
	{
		for (int i = 0; i < MaxPlayerCount - 1; i++)
		{
			pGrid->AdvanceCurrentPlayer();
			Player* otherPlayer = pGrid->GetCurrentPlayer();
			CellPosition otherpos = (otherPlayer->GetCell()->GetCellPosition());
			if (otherpos.GetCellNum() % 2 == 0)
			{
				otherPlayer->setFreezeCount(freezeCount);
				otherPlayer->setOorEPrevented(0);
				counter++;
			}
		}
	}
	if (counter == 1)
	{
		string msg = to_string(counter) + "  player is freezed for  " + to_string(freezeCount) + "turns , Click to continue";
		pOut->PrintMessage(msg);
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	else if (counter == 0 && Evensodds == 0)
	{
		string msg = "There are no players in even cells to be freezed , click to continue";
		pOut->PrintMessage(msg);
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	else if (counter == 0 && Evensodds == 1)
	{
		string msg = "There are no players in odd cells to be freezed , click to continue";
		pOut->PrintMessage(msg);
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
	else
	{
		string msg = to_string(counter) + "  players are freezed for  " + to_string(freezeCount) + " turns , Click to continue";
		pOut->PrintMessage(msg);
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
}
void Card6::Save(ofstream& OutFile, Type Type)
{
	if (Type == ObjectType)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << cardNumber << "\t" << temp.GetCellNum() << "\t" << freezeCount << "\t" << Evensodds << "\t" << endl;

	}
	else { return; }

}
void Card6::Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end)
{
	if (Type == card)
	{

		int start, cardnum;
		Infile >> cardnum >> start >> freezeCount >> Evensodds;
		cardNumber = cardnum;
		CellPosition temp(start);
		end.SetHCell(-1);
		end.SetVCell(-1);
		start1.SetHCell(temp.HCell());
		start1.SetVCell(temp.VCell());

	}
}

Card6::~Card6()
{

}
