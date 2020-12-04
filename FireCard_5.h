#pragma once

#include "Card.h"

// [ FireCard_5 ] Summary:
// Its Apply() Function:Fires all other players that are currently located at the same row or same column of the
//card by moving them to the start cell of the grid (cell number 1) and decrementing their wallets by half their current value.
// Its Parameters: no parameters
class FireCard_5 :	public Card
{
	
public:
	FireCard_5(const CellPosition & pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of FireCard_5  
	
	virtual ~FireCard_5(); // A Virtual Destructor
};