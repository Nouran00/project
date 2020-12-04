#include "Returnmortgageaction.h"

#include "Grid.h"
#include "Player.h"
#include"Card7.h"
#include "Card8.h"
#include "Card9.h"
#include "Card10.h"
#include "Card11.h"
#include "GameObject.h"


Returnmortgageaction::Returnmortgageaction(ApplicationManager* pApp) : Action(pApp)
{

}

void Returnmortgageaction::ReadActionParameters()
{
	// no parameters to read from user
}

void Returnmortgageaction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();                            //I added this (Nouran)                       






	Player* pPlayer = pGrid->GetCurrentPlayer();
	Input* pIn = pGrid->GetInput();

	//OfferMortgage* offermortgage = pGrid->GetOfferMortgage();
	Output* pOut = pGrid->GetOutput();
	Card* card;
	Card7* card7;
	Card8* card8;
	Card9* card9;
	Card10* card10;
	Card11* card11;
	string check;
	pOut->PrintMessage("Enter the city you want to return its mortgage:");
	check = pIn->GetSrting(pOut);
	if (check == "cairo" || check == "CAIRO" || check == "Cairo") {
		card = pGrid->GetTheFirstCard7();
		card7 = dynamic_cast<Card7*>(card);
		if (card7) {
			if (card7->Getownerplayer() == pPlayer) {
				if (card7->getmortgaged() == true) {

					pOut->PrintMessage("Do you want to return mortgage cairo? click y for yes or n for no");
					string actualmsg = pIn->GetSrting(pOut);
					while (actualmsg != "y" && actualmsg != "n")
					{
						pOut->PrintMessage(" Please Re-enter y for Yes or n for No: ");
						actualmsg = pIn->GetSrting(pOut);
					}
					if (actualmsg == "y")
					{
						if (pPlayer->GetWallet() > card7->getprice() * 0.7)
						{

							card7->GetMortagePlayer()->SetWallet(card7->GetMortagePlayer()->GetWallet() + card7->getprice() * 0.7);
							pPlayer->SetWallet(pPlayer->GetWallet() - card7->getprice() * 0.7);
							card7->SetMortagePlayer(NULL);
							card7->setmortgaged(false);
							pGrid->SetallCard7(pPlayer);
							string msg = " Congratulations , You have returned mortgage of CAIRO and have been deducted " + to_string(card7->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
							pOut->PrintMessage(msg);
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							card7 = NULL;
							return;
						}
						else
						{
							pOut->PrintMessage(" you don't have enough money to accept mortgage of this city . Click to continue...");
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							return;
						}
					}

				}
				else {
					pOut->PrintMessage("This city is not mortgaged. Click to continue...");
					int x, y;
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
				}
			}
			else {
				pOut->PrintMessage("You do not own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else if (check == "alex" || check == "ALEX" || check == "Alex") {
		card = pGrid->GetTheFirstCard8();
		card8 = dynamic_cast<Card8*>(card);
		if (card8) {
			if (card8->Getownerplayer() == pPlayer) {
				if (card8->getmortgaged() == true) {
					pOut->PrintMessage("Do you want to return mortgage alex? click y for yes or n for no");
					string actualmsg = pIn->GetSrting(pOut);
					while (actualmsg != "y" && actualmsg != "n")
					{
						pOut->PrintMessage(" Please Re-enter y for Yes or n for No: ");
						actualmsg = pIn->GetSrting(pOut);
					}
					if (actualmsg == "y")
					{
						if (pPlayer->GetWallet() > card8->getprice() * 0.7)
						{

							card8->GetMortagePlayer()->SetWallet(card8->GetMortagePlayer()->GetWallet() + card8->getprice() * 0.7);
							pPlayer->SetWallet(pPlayer->GetWallet() - card8->getprice() * 0.7);
							card8->SetMortagePlayer(NULL);
							card8->setmortgaged(false);
							pGrid->SetallCard8(pPlayer);
							string msg = " Congratulations , You have returned mortgage of ALEX and have been deducted " + to_string(card8->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
							pOut->PrintMessage(msg);
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							card8 = NULL;
							return;
						}
						else
						{
							pOut->PrintMessage(" you don't have enough money to accept mortgage of this city . Click to continue...");
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							return;
						}
					}

				}
				else {
					pOut->PrintMessage("This city is not mortgaged. Click to continue...");
					int x, y;
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
				}
			}
			else {
				pOut->PrintMessage("You do not own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else if (check == "aswan" || check == "ASWAN" || check == "Aswan") {
		card = pGrid->GetTheFirstCard9();
		card9 = dynamic_cast<Card9*>(card);
		if (card9) {
			if (card9->Getownerplayer() == pPlayer) {
				if (card9->getmortgaged() == true) {

					pOut->PrintMessage("Do you want to return mortgage aswan? click y for yes or n for no");
					string actualmsg = pIn->GetSrting(pOut);
					while (actualmsg != "y" && actualmsg != "n")
					{
						pOut->PrintMessage(" Please Re-enter y for Yes or n for No: ");
						actualmsg = pIn->GetSrting(pOut);
					}
					if (actualmsg == "y")
					{
						if (pPlayer->GetWallet() > card9->getprice() * 0.7)
						{

							card9->GetMortagePlayer()->SetWallet(card9->GetMortagePlayer()->GetWallet() + card9->getprice() * 0.7);
							pPlayer->SetWallet(pPlayer->GetWallet() - card9->getprice() * 0.7);
							card9->SetMortagePlayer(NULL);
							card9->setmortgaged(false);
							pGrid->SetallCard9(pPlayer);
							string msg = " Congratulations , You have returned mortgage of ASWAN and have been deducted " + to_string(card9->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
							pOut->PrintMessage(msg);
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							card9 = NULL;
							return;
						}
						else
						{
							pOut->PrintMessage(" you don't have enough money to accept mortgage of this city . Click to continue...");
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							return;
						}
					}

				}
				else {
					pOut->PrintMessage("This city is not mortgaged. Click to continue...");
					int x, y;
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
				}
			}
			else {
				pOut->PrintMessage("You do not own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else if (check == "luxor" || check == "LUXOR" || check == "Luxor") {
		card = pGrid->GetTheFirstCard10();
		card10 = dynamic_cast<Card10*>(card);
		if (card10) {
			if (card10->Getownerplayer() == pPlayer) {
				if (card10->getmortgaged() == true) {

					pOut->PrintMessage("Do you want to return mortgage luxor? click y for yes or n for no");
					string actualmsg = pIn->GetSrting(pOut);
					while (actualmsg != "y" && actualmsg != "n")
					{
						pOut->PrintMessage(" Please Re-enter y for Yes or n for No: ");
						actualmsg = pIn->GetSrting(pOut);
					}
					if (actualmsg == "y")
					{
						if (pPlayer->GetWallet() > card10->getprice() * 0.7)
						{

							card10->GetMortagePlayer()->SetWallet(card10->GetMortagePlayer()->GetWallet() + card10->getprice() * 0.7);
							pPlayer->SetWallet(pPlayer->GetWallet() - card10->getprice() * 0.7);
							card10->SetMortagePlayer(NULL);
							card10->setmortgaged(false);
							pGrid->SetallCard10(pPlayer);
							string msg = " Congratulations , You have returned mortgage of LUXOR and have been deducted " + to_string(card10->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
							pOut->PrintMessage(msg);
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							card10 = NULL;
							return;
						}
						else
						{
							pOut->PrintMessage(" you don't have enough money to accept mortgage of this city . Click to continue...");
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							return;
						}
					}

				}
				else {
					pOut->PrintMessage("This city is not mortgaged. Click to continue...");
					int x, y;
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
				}
			}
			else {
				pOut->PrintMessage("You do not own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else if (check == "hurghada" || check == "HURGHADA" || check == "Hurghada") {
		card = pGrid->GetTheFirstCard11();
		card11 = dynamic_cast<Card11*>(card);
		if (card11) {
			if (card11->Getownerplayer() == pPlayer) {
				if (card11->getmortgaged() == true) {

					pOut->PrintMessage("Do you want to return mortgage hurghada? click y for yes or n for no");
					string actualmsg = pIn->GetSrting(pOut);
					while (actualmsg != "y" && actualmsg != "n")
					{
						pOut->PrintMessage(" Please Re-enter y for Yes or n for No: ");
						actualmsg = pIn->GetSrting(pOut);
					}
					if (actualmsg == "y")
					{
						if (pPlayer->GetWallet() > card11->getprice() * 0.7)
						{

							card11->GetMortagePlayer()->SetWallet(card11->GetMortagePlayer()->GetWallet() + card11->getprice() * 0.7);
							pPlayer->SetWallet(pPlayer->GetWallet() - card11->getprice() * 0.7);
							card11->SetMortagePlayer(NULL);
							card11->setmortgaged(false);
							pGrid->SetallCard11(pPlayer);
							string msg = " Congratulations , You have returned mortgage of HURGHADA and have been deducted " + to_string(card11->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
							pOut->PrintMessage(msg);
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							card11 = NULL;
							return;
						}
						else
						{
							pOut->PrintMessage(" you don't have enough money to accept mortgage of this city . Click to continue...");
							int x, y;
							pIn->GetPointClicked(x, y);
							pOut->ClearStatusBar();
							return;
						}
					}

				}
				else {
					pOut->PrintMessage("This city is not mortgaged. Click to continue...");
					int x, y;
					pIn->GetPointClicked(x, y);
					pOut->ClearStatusBar();
				}
			}
			else {
				pOut->PrintMessage("You do not own this city. Click to continue...");
				int x, y;
				pIn->GetPointClicked(x, y);
				pOut->ClearStatusBar();
			}
		}
		else {
			pOut->PrintMessage("City not available! Click to continue...");
			int x, y;
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
		}
	}
	else
	{
		pOut->PrintMessage("This city does not exist. Click to continue... ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}

}

Returnmortgageaction::~Returnmortgageaction()
{
}
