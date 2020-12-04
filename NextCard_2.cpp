#include "NextCard_2.h"
#include "Ladder.h"
#include "Snake.h"
#include "CoinSet.h"
#include "Card.h"

NextCard_2::NextCard_2(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

NextCard_2::~NextCard_2(void)
{
}

void NextCard_2::ReadCardParameters(Grid * pGrid)
{
	
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output *pOut=pGrid->GetOutput();
	Input *pIn=pGrid->GetInput();

	// 2- Read an Integer from the user using the Input class and set the GameObjectType parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New NextCard_2: Enter choosen Game Object Type ..."
	pOut->PrintMessage("New NextCard_2: Enter choosen Game Object Type (1 means ladders, 2 snakes, 3 coin sets, 4 cards)");
	GameObjectType=pIn->GetInteger(pOut);

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void NextCard_2::Apply(Grid* pGrid, Player* pPlayer)
{
		
	Output *pOut=pGrid->GetOutput();
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	//2-Get current player podition
	Player* currplayer=pGrid->GetCurrentPlayer();
	CellPosition pos =currplayer->GetCell()->GetCellPosition();
	//3- If ladder game object was chosen (type 1)
	if (GameObjectType==1)
	{
		Ladder* Nextladder= pGrid->GetNextLadder(pos);
		if (Nextladder!=NULL)
			Nextladder->Apply(pGrid,currplayer);
		else
		{
			Ladder* previousladder= pGrid->GetPreviousLadder(pos);
			if (previousladder!=NULL)
			    previousladder->Apply(pGrid,currplayer);
			else
				pGrid->PrintErrorMessage("NO ladders found...click to continue");
		}
	}
	//4-If snake game object is choosen (type 2)
	if (GameObjectType==2)
	{
		Snake* NextSnake= pGrid->GetNextSnake(pos);
		if (NextSnake!=NULL)
			NextSnake->Apply(pGrid,currplayer);
		else
		{
			Snake* previousSnake= pGrid->GetPreviousSnake(pos);
			if (previousSnake!=NULL)
			    previousSnake->Apply(pGrid,currplayer);
			else
				pGrid->PrintErrorMessage("NO snakes found...click to continue");
		}
	}
	//5-If CoinSet game object is choosen (type 3)
	if (GameObjectType==3)
	{
		CoinSet* NextCoinSet= pGrid->GetNextCoinSet(pos);
		if (NextCoinSet!=NULL)
			{
			pGrid->UpdatePlayerCell(currplayer,NextCoinSet->GetPosition());
			NextCoinSet->Apply(pGrid,currplayer);
	        }
		else
		{
			CoinSet* previousCoinSet= pGrid->GetPreviousCoinSet(pos);
			if (previousCoinSet!=NULL)
			    {
				pGrid->UpdatePlayerCell(currplayer,previousCoinSet->GetPosition());
				previousCoinSet->Apply(pGrid,currplayer);
			}
			else
				pGrid->PrintErrorMessage("NO CoinSets found...click to continue");
		}
	}
//6-If Card game object is choosen (type 4)
	if (GameObjectType==4)
	{
		Card* NextCard= pGrid->GetNextCard(pos);
		if (NextCard!=NULL)
			{
			pGrid->UpdatePlayerCell(currplayer,NextCard->GetPosition());
			NextCard->Apply(pGrid,currplayer);
		}
		else
		{
			Card* previousCard= pGrid->GetPreviousCard(pos);
			if (previousCard!=NULL)
			   {
				pGrid->UpdatePlayerCell(currplayer,previousCard->GetPosition());
				previousCard->Apply(pGrid,currplayer);
			}
			else
				pGrid->PrintErrorMessage("NO Cards found...click to continue");
	    }
	}
	
}
void NextCard_2::Save(ofstream& OutFile, Type Type)
{
	if (Type == ObjectType)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << cardNumber << "\t" << temp.GetCellNum() << "\t" << GameObjectType << "\t" << endl;

	}
	else { return; }

}
void NextCard_2::Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end)
{
	if (Type == card)
	{

		int start, cardnum;
		Infile >> cardnum >> start >> GameObjectType;
		cardNumber = cardnum;
		CellPosition temp(start);
		end.SetHCell(-1);
		end.SetVCell(-1);
		start1.SetHCell(temp.HCell());
		start1.SetVCell(temp.VCell());

	}
}
