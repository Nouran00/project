#pragma once
#include "GameObject.h"
#include "Player.h"
#include<fstream>

// Base Class of All Types of Cards (DecWalletCard_1, ...etc.)
// Note: We will make each type of Card in a separate class because:
// it may have additional data members and functions like: Apply(), ...etc. which have different implementation depending on Card type
class Card : public GameObject
{
protected:
	int cardNumber; // an integer representing the card number
	const Type ObjectType;

public:
	
	Card(const CellPosition & pos); // A Constructor for card that takes the cell position of it
	Card();
	void SetCardNumber(int cnum);   // The setter of card number

	int GetCardNumber();            // The getter of card number

	void Draw(Output* pOut) const;  // Draws the card number in the cell position of the card
	                                // It has the same implementation for all Card Types (Non-Virtual)

	virtual void ReadCardParameters(Grid * pGrid); // It reads the parameters specific for each Card Type
	                                               // It is a virtual function (implementation depends on Card Type)

	virtual void Apply(Grid* pGrid, Player* pPlayer);  // It applies the effect of the Card Type on the passed player
	                                                   // It is a virtual function (implementation depends on Card Type)

	virtual ~Card(); // A Virtual Destructor
	void Save(ofstream& OutFile, Type Type);
	void Load(ifstream& Infile, Type Type, CellPosition& start, CellPosition& end);

};

