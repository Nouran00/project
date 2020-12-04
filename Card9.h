#pragma once
#include "Card.h"
#include "GameObject.h"
#include<fstream>

class Card9 : public Card
{
	static int FeesToPay;
	static int CardPrice;
	Player* OwnerPlayer;
	Player* TempNonOwner;
	bool mortgaged;
	bool ChecktoReturnOwnership;
	Player* MortagePlayer;

public:

	Card9(const CellPosition& pos);
	Card9();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void SetOwnerPlayer(Player* pPlayer);
	Player* Getownerplayer();
	void setfeestopay(int fees);
	int getfeestopay();
	int getprice();
	void setprice(int price);
	bool getmortgaged();
	void setmortgaged(bool x);
	void SetTempNonOwner(Player* temp);
	Player* GetTempNonOwner();
	bool getChecktoReturnOwnership();
	void setChecktoReturnOwnership(bool y);
	void SetMortagePlayer(Player* pPlayer);
	Player* GetMortagePlayer();
	void Save(ofstream& OutFile, Type Type);
	void Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end);
	virtual ~Card9();

};