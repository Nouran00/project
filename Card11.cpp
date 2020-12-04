#include "Card11.h"

Card11::Card11(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (11 here)
	OwnerPlayer = NULL; //initialize the ownerplayer to null
	mortgaged = 0;
	TempNonOwner = NULL;
	ChecktoReturnOwnership = false;
	MortagePlayer = NULL;
}

Card11::Card11()
{
	cardNumber = 11;
	OwnerPlayer = NULL;
	mortgaged = 0;
	TempNonOwner = NULL;
	ChecktoReturnOwnership = false;
	MortagePlayer = NULL;
}

void Card11::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card* pCard = pGrid->GetTheFirstCard11();
	if (pCard)
	{
		pOut->PrintMessage("New Card11, Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
		Card11* FirstCard11 = dynamic_cast <Card11*> (pCard);
		CardPrice = FirstCard11->CardPrice;
		FeesToPay = FirstCard11->FeesToPay;
		return;
	}
	pOut->PrintMessage("New Card11, Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Enter its CardPrice ...");
	CardPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage(" Enter the fees you  want any other player to pay ...");
	FeesToPay = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void Card11::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card::Apply(pGrid, pPlayer);
	if (!OwnerPlayer)
	{
		pOut->PrintMessage("You have reached HURGHADA Do you want to buy this city ? (y/n) ");
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
				string msg = " Congratulations , You bought HURGHADA and have been deducted " + to_string(CardPrice) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
				pOut->PrintMessage(msg);
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
				OwnerPlayer = pPlayer;
				pGrid->SetallCard11(OwnerPlayer);
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

void Card11::SetOwnerPlayer(Player* pPlayer)
{
	OwnerPlayer = pPlayer;
}

Player* Card11::Getownerplayer()
{
	return OwnerPlayer;
}

void Card11::setfeestopay(int fees)
{
	FeesToPay = fees;
}

int Card11::getfeestopay()
{
	return FeesToPay;
}

int Card11::getprice()
{
	return CardPrice;
}

void Card11::setprice(int price)
{
	CardPrice = price;
}

bool Card11::getmortgaged()
{
	return mortgaged;
}

void Card11::setmortgaged(bool x) {
	mortgaged = x;
}

void Card11::SetTempNonOwner(Player* temp)
{
	TempNonOwner = temp;
}

Player* Card11::GetTempNonOwner()
{
	return TempNonOwner;
}

bool Card11::getChecktoReturnOwnership()
{
	return ChecktoReturnOwnership;
}

void Card11::setChecktoReturnOwnership(bool y)
{
	ChecktoReturnOwnership = y;
}

void Card11::SetMortagePlayer(Player* pPlayer)
{
	MortagePlayer = pPlayer;
}

Player* Card11::GetMortagePlayer()
{
	return MortagePlayer;
}
void Card11::Save(ofstream& OutFile, Type Type)
{
	if (Type == ObjectType)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << cardNumber << "\t" << temp.GetCellNum() << "\t" << CardPrice << "\t" << FeesToPay << "\t" << endl;

	}
	else { return; }

}
void Card11::Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end)
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

Card11::~Card11()
{}

int Card11::FeesToPay = 0; // fees to the player who owns the cell
int Card11::CardPrice = 0; // the card price