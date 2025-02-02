#pragma once

#include "Grid.h"

// Base Class for All Game Objects ( ladders, snakes, coins and cards )
class GameObject
{

protected:

	CellPosition position; // The current cell position of the GameObject

public:

	GameObject(const CellPosition& pos); // Constructor for initializing data members
	GameObject();

	CellPosition GetPosition() const;     // A Getter for position

	// ============ Virtual Functions ============

	virtual void Draw(Output* pOut) const = 0;	 // Draws the game object in the window in his position cell 
												 // (drawing depends on GameObject Type, so virtual)

	virtual void Apply(Grid* pGrid, Player* pPlayer) = 0;  // Applys the effect of the GameObject on the passed Player
														   // (The effect depends on the GameObject type, so virtual)
														   // For example, applying a ladder is by moving player up, and so on

	// The following functions are examples of what should be supported by the GameObject class
	// They should be overridden by each inherited class

	// Decide the parameters that you should pass to each function	

	//virtual void Save(ofstream &OutFile) = 0;	// Saves the GameObject parameters to the file --> feel free to change this prototype as needed
	//virtual void Load(ifstream &Infile) = 0;	// Loads and Reads the GameObject parameters from the file --> feel free to change this prototype as needed
	virtual void Save(ofstream& OutFile, Type Type) = 0;

	virtual void Load(ifstream& Infile, Type Type, CellPosition& start, CellPosition& end)= 0;

	virtual ~GameObject(); // Virtual destructor
};

