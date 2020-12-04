#pragma once

#include "Card.h"
#include "GameObject.h"
#include<fstream>

// [ NextCard_2 ] Summary:
// Its Apply() Function: Moves the current player forward to the start of the next game object of a chosen type (ladder, snake, coin set or cards).
//If no gameobjects in the cells after player ,search  the cells before player position.If no objects before dont move.
// Its Parameters: A number indicating the game object type to move to (1 means ladders, 2 snakes, 3 coin sets, 4 cards).
class NextCard_2 :	public Card
{
	// NextCard_2 Parameters:
	int GameObjectType; // A number indicating the type of game object to move to (1 means ladders, 2 snakes, 3 coin sets, 4 cards).

public:
	NextCard_2(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of NextCard_2 which is: GameObjectType

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of NextCard_2 on the passed Player
	                                                  // by moving forward to the start of the next game object
	
	virtual ~NextCard_2(); // A Virtual Destructor
	void Save(ofstream& OutFile, Type Type);
	void Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end);
};