#include "SellCity.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"
#include "Card.h"
#include"Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "GameObject.h"
SellCity::SellCity(ApplicationManager* pApp) : Action(pApp)
{
	//Execute();
}

void SellCity::ReadActionParameters()
{
	// no parameters to read from user
}

void SellCity::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();                            //I added this (Nouran)                       


	Player* pPlayer = pGrid->GetCurrentPlayer();                           //I added this (Nouran)

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Card* card;
	Card7* card7;
	Card8* card8;
	Card9* card9;
	Card10* card10;
	Card11* card11;
	pOut->PrintMessage("Input the city that you want to sell: ");

	string CityToCell = pIn->GetSrting(pOut);


	//Card card7 = 

	//Player* owner7 = Card7->Getownerplayer();

	if (CityToCell == "Cairo" || CityToCell == "cairo" || CityToCell == "CAIRO")
	{
		card = pGrid->GetTheFirstCard7();
		card7 = dynamic_cast<Card7*>(card);
		if (card7) {
			Player* owner = card7->Getownerplayer();
			//card7->Sell(pPlayer, pGrid);
			if (owner == pPlayer) {
				pOut->PrintMessage("Sold ");

				pPlayer->SetWallet(pPlayer->GetWallet() + card7->getprice() * 0.9);
				card7->SetOwnerPlayer(NULL);
				//return;
			}
			else {
				pOut->PrintMessage(" you don't own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else 	if (CityToCell == "Alex" || CityToCell == "alex" || CityToCell == "ALEX")
	{
		card = pGrid->GetTheFirstCard8();
		pIn = pGrid->GetInput();
		card8 = dynamic_cast<Card8*>(card);
		if (card8) {
			Player* owner = card8->Getownerplayer();
			//card8->Sell(pPlayer, pGrid);
			if (owner == pPlayer) {
				pOut->PrintMessage("Sold ");

				pPlayer->SetWallet(pPlayer->GetWallet() + card8->getprice() * 0.9);
				card8->SetOwnerPlayer(NULL);
				//return;
			}
			else {
				pOut->PrintMessage(" you don't own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else 	if (CityToCell == "Aswan" || CityToCell == "aswan" || CityToCell == "ASWAN")
	{
		card = pGrid->GetTheFirstCard9();
		pIn = pGrid->GetInput();
		card9 = dynamic_cast<Card9*>(card);
		if (card9) {
			Player* owner = card9->Getownerplayer();
			//card9->Sell(pPlayer, pGrid);
			if (owner == pPlayer) {
				pOut->PrintMessage("Sold ");

				pPlayer->SetWallet(pPlayer->GetWallet() + card9->getprice() * 0.9);
				card9->SetOwnerPlayer(NULL);
				//return;
			}
			else {
				pOut->PrintMessage(" you don't own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else 	if (CityToCell == "Luxor" || CityToCell == "luxor" || CityToCell == "LUXOR")
	{
		card = pGrid->GetTheFirstCard10();
		pIn = pGrid->GetInput();
		card10 = dynamic_cast<Card10*>(card);
		if (card10) {
			Player* owner = card10->Getownerplayer();
			//card10->Sell(pPlayer, pGrid);
			if (owner == pPlayer) {
				pOut->PrintMessage("Sold ");

				pPlayer->SetWallet(pPlayer->GetWallet() + card10->getprice() * 0.9);
				card10->SetOwnerPlayer(NULL);
				//return;
			}
			else {
				pOut->PrintMessage(" you don't own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else 	if (CityToCell == "Hurghada" || CityToCell == "hurghada" || CityToCell == "HURGHADA")
	{
		card = pGrid->GetTheFirstCard11();
		pIn = pGrid->GetInput();
		card11 = dynamic_cast<Card11*>(card);
		if (card11) {
			Player* owner = card11->Getownerplayer();
			//card11->Sell(pPlayer, pGrid);
			if (owner == pPlayer) {
				pOut->PrintMessage("Sold ");

				pPlayer->SetWallet(pPlayer->GetWallet() + card11->getprice() * 0.9);
				card11->SetOwnerPlayer(NULL);
				//return;
			}
			else {
				pOut->PrintMessage(" you don't own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else {
		pOut->PrintMessage("This city does not exist. Click to continue... ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}

	pGrid->AdvanceCurrentPlayer();
	/*
	player->Move(pGrid, diceNumber);                                       //I added this (Nouran)
	// 5- Advance the current player number of pGrid
	pGrid->AdvanceCurrentPlayer();                                        //I added this (Nouran)

	*/
	return;
}

SellCity::~SellCity()
{
}