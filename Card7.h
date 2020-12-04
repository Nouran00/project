#pragma once
#include "Card.h"
#include "GameObject.h"
#include<fstream>


class Card7 : public Card
{
	static int FeesToPay;
	static int CardPrice;
	Player* OwnerPlayer;
	Player* TempNonOwner;
	bool ChecktoReturnOwnership;
	bool mortgaged;
	Player* MortagePlayer;

public:

	Card7(const CellPosition& pos);
	Card7();
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void SetOwnerPlayer(Player* pPlayer);
	Player* Getownerplayer();
	void SetTempNonOwner(Player* temp);
	Player* GetTempNonOwner();
	void setfeestopay(int fees);
	int getfeestopay();
	int getprice();
	void setprice(int price);
	bool getmortgaged();
	void setmortgaged(bool x);
	bool getChecktoReturnOwnership();
	void setChecktoReturnOwnership(bool y);
	void SetMortagePlayer(Player* pPlayer);
	Player* GetMortagePlayer();
	
	void Save(ofstream& OutFile, Type Type);
	void Load(ifstream& Infile, Type Type, CellPosition& start1, CellPosition& end);
	virtual ~Card7();


};