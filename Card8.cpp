#include "Card8.h"
Card8::Card8(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (8 here)
	OwnerPlayer = NULL;
	mortgaged = 0;
	TempNonOwner = NULL;
	ChecktoReturnOwnership = false;
	MortagePlayer = NULL;
}

Card8::Card8()
{
	cardNumber = 8;
	OwnerPlayer = NULL;
	mortgaged = 0;
	TempNonOwner = NULL;
	ChecktoReturnOwnership = false;
	MortagePlayer = NULL;
}

void Card8::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card* pCard = pGrid->GetTheFirstCard8();
	if (pCard)
	{
		pOut->PrintMessage("New Card8, Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		Card8* FirstCard8 = dynamic_cast <Card8*> (pCard);
		CardPrice = FirstCard8->CardPrice;
		FeesToPay = FirstCard8->FeesToPay;
		return;
	}
	pOut->PrintMessage("New Card8, Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Enter its CardPrice ...");
	CardPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage(" Enter the fees you  want any other player to pay ...");
	FeesToPay = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void Card8::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	if (!OwnerPlayer)
	{
		pOut->PrintMessage("You have reached ALEX Do you want to buy this city ? (y/n) ");
		string actualmsg = pIn->GetSrting(pOut);
		while (actualmsg != "y" && actualmsg != "n")
		{
			pOut->PrintMessage(" Please Re-enter y for Yes and n for No: ");
			actualmsg = pIn->GetSrting(pOut);
		}
		if (actualmsg == "y")
		{
			if (pPlayer->GetWallet() > CardPrice)
			{

				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				string msg = " Congratulations , You bought ALEX and have been deducted " + to_string(CardPrice) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				OwnerPlayer = pPlayer;
				pGrid->SetallCard8(OwnerPlayer);
				return;
			}
			else
			{
				pOut->PrintMessage(" you don't have enough money to buy this city . Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				return;
			}
		}
		else
		{
			pOut->ClearStatusBar();
			return;
		}
	}
	else
	{
		if (getmortgaged() == false) {
			if (pPlayer->getPlayerNum() != OwnerPlayer->getPlayerNum())
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - FeesToPay);
				OwnerPlayer->SetWallet(OwnerPlayer->GetWallet() + FeesToPay);
				string msg = " Another player has landed on your city and paid " + to_string(FeesToPay) + " , Your new wallet amount is equal to " + to_string(OwnerPlayer->GetWallet());
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				return;
			}
		}
		else {
			if (pPlayer->getPlayerNum() != MortagePlayer->getPlayerNum())
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - FeesToPay);
				MortagePlayer->SetWallet(MortagePlayer->GetWallet() + FeesToPay);
				string msg = " Another player has landed on your city and paid " + to_string(FeesToPay) + " , Your new wallet amount is equal to " + to_string(MortagePlayer->GetWallet());
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				return;
			}
		}
	}
}

void Card8::SetOwnerPlayer(Player* pPlayer)
{
	OwnerPlayer = pPlayer;
}

Player* Card8::Getownerplayer()
{
	return OwnerPlayer;
}

void Card8::setfeestopay(int fees)
{
	FeesToPay = fees;
}

int Card8::getfeestopay()
{
	return FeesToPay;
}

int Card8::getprice()
{
	return CardPrice;
}

void Card8::setprice(int price)
{
	CardPrice = price;
}

bool Card8::getmortgaged()
{
	return mortgaged;
}

void Card8::setmortgaged(bool x)
{
	mortgaged = x;
}

void Card8::SetTempNonOwner(Player* temp)
{
	TempNonOwner = temp;
}

Player* Card8::GetTempNonOwner()
{
	return TempNonOwner;
}

bool Card8::getChecktoReturnOwnership()
{
	return ChecktoReturnOwnership;
}

void Card8::setChecktoReturnOwnership(bool y)
{
	ChecktoReturnOwnership = y;
}

void Card8::SetMortagePlayer(Player* pPlayer)
{
	MortagePlayer = pPlayer;
}

Player* Card8::GetMortagePlayer()
{
	return MortagePlayer;
}
void Card8::Save(ofstream& OutFile, Type Type)
{
	if (Type == ObjectType)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << cardNumber << "\t" << temp.GetCellNum() << "\t" << CardPrice << "\t" << FeesToPay << "\t" << endl;

	}
	else { return; }

}
void Card8::Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end)
{
	if (Type == card)
	{

		int start, cardnum;
		Infile >> cardnum >> start >> CardPrice >> FeesToPay;
		cardNumber = cardnum;
		CellPosition temp(start);
		end.SetHCell(-1);
		end.SetVCell(-1);
		start1.SetHCell(temp.HCell());
		start1.SetVCell(temp.VCell());

	}
}

Card8::~Card8()
{}

int Card8::FeesToPay = 0; // fees to the player who owns the cell
int Card8::CardPrice = 0; // the card price