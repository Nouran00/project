#pragma once

#include "Card.h"

// [ PreventCard_4 ] Summary:
// Its Apply() Function: Prevents one of the other players from rolling the next turn.
// Its Parameters: no parameters during grid design
class PreventCard_4 :	public Card
{
public:
	PreventCard_4(const CellPosition & pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of PreventCard_4  by Preventing one of the 
	                                                  //other players from rolling the next turn.
	                                                
	virtual ~PreventCard_4(); // A Virtual Destructor
};