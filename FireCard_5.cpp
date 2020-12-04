#include "FireCard_5.h"

FireCard_5::FireCard_5(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (5 here)
}

FireCard_5::~FireCard_5(void)
{
}
void FireCard_5::Apply(Grid* pGrid, Player* pPlayer)
{
		
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output *pOut=pGrid->GetOutput();


	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// apply card function as described in .h file
	Player * currPlayer=pGrid->GetCurrentPlayer();
	CellPosition pos=(currPlayer->GetCell())->GetCellPosition();
	int hor_cell=pos.HCell();
	int ver_cell=pos.VCell();
	for (int i=0;i<MaxPlayerCount-1;i++)
	{
		pGrid->AdvanceCurrentPlayer();
		Player *otherPlayer=pGrid->GetCurrentPlayer();
		CellPosition otherpos= (   ( otherPlayer->GetCell() )  ->  GetCellPosition()  );
		if (otherpos.HCell() ==hor_cell || otherpos.VCell() ==ver_cell )
		{
			int new_wallet= (int)( otherPlayer->GetWallet() ) /2;
			otherPlayer->SetWallet(   new_wallet   );
			otherpos.SetHCell(0);
			otherpos.SetVCell(8);
			pGrid->UpdatePlayerCell(otherPlayer,otherpos); 
		}
		
	}
	pGrid->PrintErrorMessage("other players in the same row or colomn are moved to first cell and wallet decremented by half" );	
	pGrid->AdvanceCurrentPlayer();	
    

	
}
