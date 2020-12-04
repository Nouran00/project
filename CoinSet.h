#pragma once

#include "GameObject.h"
#include "Player.h"
#include<fstream>

class CoinSet : public GameObject
{
protected:
	int Amount; // an integer specifying how many coins in the set
	const Type ObjectType;

public:
	CoinSet(const CellPosition& pos); // A Constructor for coinset that takes the cell position of it

	void SetAmount(int A);   // The setter of coinset amount
	int GetAmount();            // The getter of coinset amount

	virtual void Draw(Output* pOut) const;  // Draws the coinset in the cell position of the coinset


	void ReadCoinSetAmount(Grid* pGrid); // It reads the "Amount" specific for the coinset from user


	virtual void Apply(Grid* pGrid, Player* pPlayer);  // It applies the effect of the Coinset on the passed player 
													   //by adding amount to his wallet

	void Save(ofstream& OutFile, Type Type);
	void Load(ifstream& Infile, Type Type, CellPosition& start, CellPosition& end);
	virtual ~CoinSet(); // A Virtual Destructor
};