#pragma once
#include "GameObject.h"
#include "Card.h"
#include<fstream>

// [ DecWalletCard_1 ] Summary:
// Its Apply() Function: Decrements the value of the passing player�s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class DecWalletCard_1 :	public Card
{
	// DecWalletCard_1 Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	DecWalletCard_1(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	
	virtual ~DecWalletCard_1(); // A Virtual Destructor
	void Save(ofstream& OutFile, Type Type);

	void Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end);
	
};

