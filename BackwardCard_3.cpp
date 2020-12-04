#include "BackwardCard_3.h"

BackwardCard_3::BackwardCard_3(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

BackwardCard_3::~BackwardCard_3(void)
{
}

void BackwardCard_3::Apply(Grid* pGrid, Player* pPlayer)
{
	Output *pOut=pGrid->GetOutput();
	// 1- Calling Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// 2-Moving all other players backward the same number of steps that the current player just rolled
	Player * currPlayer=pGrid->GetCurrentPlayer();
	int diceNumber=currPlayer->GetjustRolledDiceNum();
	for (int i=0;i<MaxPlayerCount-1;i++)
	{
		pGrid->AdvanceCurrentPlayer();
		Player *otherPlayer=pGrid->GetCurrentPlayer();
		CellPosition pos= (   ( otherPlayer->GetCell() )  ->  GetCellPosition()  );
		pos.AddCellNum(diceNumber*-1);
		int newCellNum=pos.GetCellNum();
		pGrid->UpdatePlayerCell(otherPlayer,pos); 
		 GameObject *gameobject= (   ( otherPlayer->GetCell() )  ->GetGameObject()   );
		 if(gameobject!=NULL)
			gameobject->Apply(pGrid,otherPlayer);
	}
pGrid->AdvanceCurrentPlayer();	
pOut->PrintMessage("other players moved back " +to_string(pPlayer->GetjustRolledDiceNum())+ " cells");
}
