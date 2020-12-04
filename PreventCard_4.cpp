#include "PreventCard_4.h"

PreventCard_4::PreventCard_4(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (4 here)
}

PreventCard_4::~PreventCard_4(void)
{
}

void PreventCard_4::Apply(Grid* pGrid, Player* pPlayer)
{
		
	Output *pOut=pGrid->GetOutput();
	Input *pIn=pGrid->GetInput();
	int x=0;
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pOut->PrintMessage("click player to be prevented from movement next turn");
	// 2-Apply the card effect
	CellPosition clickedpos= pIn->GetCellClicked();
	for (int i=0; i<MaxPlayerCount-1; i++)
	{
		pGrid->AdvanceCurrentPlayer();
		Player *otherplayer=pGrid->GetCurrentPlayer();
		CellPosition pos= (   ( otherplayer->GetCell() )  ->  GetCellPosition()  );
		if (pos.HCell()==clickedpos.HCell() && pos.VCell()==clickedpos.VCell())
		{
			otherplayer->SetDontMove(true);
			x++;
		}
	}
	pGrid->AdvanceCurrentPlayer();
	if(x==0)
		pGrid->PrintErrorMessage("clicked cell is invalid....click to continue");
	else
	pGrid->PrintErrorMessage("clicked player will be prevented from rolling dice next trun");

}