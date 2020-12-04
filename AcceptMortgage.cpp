#include "AcceptMortgage.h"
#include "OfferMortgage.h"

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

AcceptMortgage::AcceptMortgage(ApplicationManager* pApp) : Action(pApp)
{
	//Execute();
}

void AcceptMortgage::ReadActionParameters()
{
	// no parameters to read from user
}

void AcceptMortgage::Execute()
{
	Grid* pGrid = pManager->GetGrid();

	Player* pPlayer = pGrid->GetCurrentPlayer();
	Input* pIn = pGrid->GetInput();

	OfferMortgage* offermortgage = pGrid->GetOfferMortgage();
	Output* pOut = pGrid->GetOutput();
	Card* card_7;
	Card* card_8;
	Card* card;
	Card7* card7;
	Card8* card8;
	Card9* card9;
	Card10* card10;
	Card11* card11;
	string check;
	pOut->PrintMessage("Enter the city you want to accept its mortgage:");
	check = pIn->GetSrting(pOut);
	if (check == "cairo" || check == "CAIRO" || check == "Cairo") {
		card_7 = pGrid->GetTheFirstCard7();
		card7 = dynamic_cast<Card7*>(card_7);
		if (card7) {
			if (card7->getmortgaged() == false) {

				pOut->PrintMessage("Do you want to mortgage cairo? click y for yes or n for no");
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

						card7->SetMortagePlayer(pPlayer);
						card7->setmortgaged(true);
						pGrid->SetSemiCard7(pPlayer);
						card7->Getownerplayer()->SetWallet(card7->Getownerplayer()->GetWallet() + card7->getprice() * 0.7);
						pPlayer->SetWallet(pPlayer->GetWallet() - card7->getprice() * 0.7);
						string msg = " Congratulations , You have accepted mortgaged of CAIRO and have been deducted " + to_string(card7->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
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
				pOut->PrintMessage("Another player already accepted the mortgage");
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
		card_8 = pGrid->GetTheFirstCard8();
		card8 = dynamic_cast<Card8*>(card_8);
		if (card8) {
			if (card8->getmortgaged() == false) {
				if (card8 != NULL)
				{

					pOut->PrintMessage("Do you want to mortgage alex? click y for yes or n for no");
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

							card8->SetMortagePlayer(pPlayer);
							card8->setmortgaged(true);
							pGrid->SetSemiCard8(pPlayer);
							card8->Getownerplayer()->SetWallet(card8->Getownerplayer()->GetWallet() + card8->getprice() * 0.7);
							pPlayer->SetWallet(pPlayer->GetWallet() - card8->getprice() * 0.7);
							string msg = " Congratulations , You have accepted mortgaged of ALEX and have been deducted " + to_string(card8->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
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

			}
			else {
				pOut->PrintMessage("Another player already accepted the mortgage");
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
			if (card9->getmortgaged() == false) {
				if (card9 != NULL)
				{

					pOut->PrintMessage("Do you want to mortgage aswan? click y for yes or n for no");
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

							card9->SetMortagePlayer(pPlayer);
							card9->setmortgaged(true);
							pGrid->SetSemiCard9(pPlayer);
							card9->Getownerplayer()->SetWallet(card9->Getownerplayer()->GetWallet() + card9->getprice() * 0.7);
							pPlayer->SetWallet(pPlayer->GetWallet() - card9->getprice() * 0.7);
							string msg = " Congratulations , You have accepted mortgaged of ASWAN and have been deducted " + to_string(card9->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
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

			}
			else {
				pOut->PrintMessage("Another player already accepted the mortgage");
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
			if (card10->getmortgaged() == false) {
				if (card10 != NULL)
				{

					pOut->PrintMessage("Do you want to mortgage luxor? click y for yes or n for no");
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

							card10->SetMortagePlayer(pPlayer);
							card10->setmortgaged(true);
							pGrid->SetSemiCard10(pPlayer);
							card10->Getownerplayer()->SetWallet(card10->Getownerplayer()->GetWallet() + card10->getprice() * 0.7);
							pPlayer->SetWallet(pPlayer->GetWallet() - card10->getprice() * 0.7);
							string msg = " Congratulations , You have accepted mortgaged of LUXOR and have been deducted " + to_string(card10->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
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

			}
			else {
				pOut->PrintMessage("Another player already accepted the mortgage");
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
			if (card11->getmortgaged() == false) {
				if (card11 != NULL)
				{

					pOut->PrintMessage("Do you want to mortgage hurghada? click y for yes or n for no");
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

							card11->SetMortagePlayer(pPlayer);
							card11->setmortgaged(true);
							pGrid->SetSemiCard11(pPlayer);
							card11->Getownerplayer()->SetWallet(card11->Getownerplayer()->GetWallet() + card11->getprice() * 0.7);
							pPlayer->SetWallet(pPlayer->GetWallet() - card11->getprice() * 0.7);
							string msg = " Congratulations , You have accepted mortgaged of HURGHADA and have been deducted " + to_string(card11->getprice() * 0.7) + " from your wallet , Your new wallet amount is equal to " + to_string(pPlayer->GetWallet());
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

			}
			else {
				pOut->PrintMessage("Another player already accepted the mortgage");
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
	else {
		pOut->PrintMessage("This city does not exist. ");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}

	/*	if (offermortgage->card8 != NULL)
		{
			pOut->PrintMessage("Do you want to mortage alex");
		}
		if (offermortgage->card9 != NULL)
		{
			pOut->PrintMessage("Do you want to mortage Aswan");
		}
		if (offermortgage->card10 != NULL)
		{
			pOut->PrintMessage("Do you want to mortage luxor");
		}
		if (offermortgage->card11 != NULL)
		{
			pOut->PrintMessage("Do you want to mortage Hurgada");
		}*/
}
AcceptMortgage::~AcceptMortgage()
{
}