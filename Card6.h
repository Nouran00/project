#pragma once
#include "Card.h"
#include "GameObject.h"
#include<fstream>


class Card6 : public Card
{
	int freezeCount;
	bool Evensodds;

public:

	Card6(const CellPosition& pos);
	Card6();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~Card6();
	void Save(ofstream& OutFile, Type Type);

	void Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end);

};