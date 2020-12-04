#pragma once
#include "Card.h"

class Card13 : public Card
{

public:

	Card13(const CellPosition& pos);
	Card13();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~Card13();

};