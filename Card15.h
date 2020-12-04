#pragma once
#include "Card.h"
#include "GameObject.h"
#include<fstream>


class Card15 : public Card
{

	int numberofturns;

public:

	Card15(const CellPosition& pos);
	Card15();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream& OutFile, Type Type);
	void Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end);
	virtual ~Card15();

};