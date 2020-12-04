#include "CoinSet.h"
CoinSet::CoinSet(const CellPosition& pos) : GameObject(pos), ObjectType(coinset)  // sets the cell position of the GameObject
{
}

void CoinSet::SetAmount(int A)
{
	if (A < 0)
		return;
	else
		Amount = A;
}

int CoinSet::GetAmount()
{
	return Amount;
}

void CoinSet::Draw(Output* pOut) const
{
	pOut->DrawCoinSet(position);
}

void CoinSet::ReadCoinSetAmount(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("New CoinSet: Enter its amount ...");
	Amount = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void CoinSet::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	pGrid->PrintErrorMessage("You have reached a CoinSet. Click to continue ...");
	pPlayer->SetWallet((pPlayer->GetWallet()) + Amount);
	pOut->PrintMessage("Coin set amount" + to_string(Amount) + "added to wallet");

}

void CoinSet::Save(ofstream& OutFile, Type Type)
{
	if (Type == ObjectType)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << temp.GetCellNum() << "\t" << Amount << "\t" << endl;

	}
	else { return; }
}

void CoinSet::Load(ifstream& Infile, Type Type, CellPosition& start2, CellPosition& end2)
{
	if (Type == coinset)
	{

		int start, amount;
		Infile >> amount >> start;
		Amount = amount;
		CellPosition temp(start);
		end2.SetHCell(-1);
		end2.SetVCell(-1);
		start2.SetHCell(temp.HCell());
		start2.SetVCell(temp.VCell());

	}
}

CoinSet::~CoinSet()
{
}
