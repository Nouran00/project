#include "Card.h"
Card::Card(const CellPosition & pos) : GameObject(pos), ObjectType(card) // sets the cell position of the GameObject
{
}
Card::Card():ObjectType(card)
{
}
void Card::SetCardNumber(int cnum)
{
	if (cnum<1 || cnum>15)
		return;
	else
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}



void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position,cardNumber);

}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	
	// The following line is to print the following message if a player reaches a card of any type

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, Type Type)
{
	if (Type == ObjectType)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << cardNumber << "\t" << temp.GetCellNum() << "\t" << endl;

	}
	else { return; }

}

void Card::Load(ifstream & Infile, Type Type, CellPosition& start1 , CellPosition& end)
{
	if (Type == card)
	{

		int start, cardnum;
		Infile >> cardnum >> start;
		cardNumber = cardnum;
		CellPosition temp(start);
		end.SetHCell(-1);
		end.SetVCell(-1);
		start1.SetHCell(temp.HCell());
		start1.SetVCell(temp.VCell());

	}
}


Card::~Card()
{
}
