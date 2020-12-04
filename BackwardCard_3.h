#pragma once

#include "Card.h"

// [ DecWalletCard_1 ] Summary:
// Its Apply() Function:Move all other players backward the same number of steps that the current player just
//rolled (if they reach a ladder, snake or coins at the end of moving, take it).
// Its Parameters: no parameters
class BackwardCard_3 :	public Card
{
	
public:
	BackwardCard_3(const CellPosition & pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of BackwardCard_3  
	
	virtual ~BackwardCard_3(); // A Virtual Destructor
};