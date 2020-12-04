#pragma once
#include "Card.h"

class Card14 : public Card
{

public:

	Card14(const CellPosition& pos);
	Card14();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~Card14();

};