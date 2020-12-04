#pragma once

#include "GameObject.h"
#include<fstream>

class Snake : public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the Snake's "Start Cell Position"

	CellPosition endCellPos; // here is the Snake's End Cell Position
	const Type ObjectType;

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a Snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the Snake by moving player to Snake's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	void Save(ofstream& OutFile, Type Type);
	void Load(ifstream& Infile, Type Type, CellPosition& start, CellPosition& end);
	virtual ~Snake(); // Virtual destructor
};