#pragma once
#include "Card.h"


class Card12 : public Card
{

public:

	Card12(const CellPosition& pos); // A Constructor takes card position
	virtual void ReadCardParameters(Grid* pGrid); // It reads the parameters specific for each Card Type										   // It is a virtual function (implementation depends on Card Type)
	Card12();
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player													  // by decrementing the player's wallet by the walletAmount data membe
	virtual ~Card12(); // A Virtual Destructor

};