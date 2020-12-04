#include "OpenGridAction.h"
#include"Card11.h"
#include"Card12.h"
#include"Card13.h"
#include"Card14.h"
#include"Card15.h"
#include"Card6.h"
#include"Card7.h"
#include"Card8.h"
#include"Card9.h"
#include"DecWalletCard_1.h"
#include"FireCard_5.h"
#include"NextCard_2.h"
#include"PreventCard_4.h"
#include"CoinSet.h"
#include"Snake.h"
#include"Ladder.h"
#include"BackwardCard_3.h"
#include"Card10.h"
#include"Grid.h"
OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp)
{
}

void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = Action::pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter the name of the file to open......");
	name = pIn->GetSrting(pOut);
	opendata.open(name + ".txt");
}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = Action::pManager->GetGrid();
	if (opendata.fail())
	{
		pGrid->PrintErrorMessage("Error openning txt file...");

	}
	else
	{
		pGrid->DeleteAll();
		pGrid->UpdateInterface();
		int NumofLadders;
		opendata >> NumofLadders;
		for (int i = 0; i < NumofLadders; i++)
		{
			Ladder* pLadder;
			CellPosition start;
			CellPosition end;
			pLadder = new Ladder(start, end);
			pLadder->Load(opendata, ladder, start, end);
			delete pLadder;
			pLadder = new Ladder(start, end);
			pGrid->AddObjectToCell(pLadder);
			pGrid->GetOutput()->DrawLadder(start, end);
		}
		int NumofSnakes;
		opendata >> NumofSnakes;
		for (int i = 0; i < NumofSnakes; i++)
		{
			Snake* pSnake;
			CellPosition start;
			CellPosition end;
			pSnake = new Snake(start, end);
			pSnake->Load(opendata, snake, start, end);
			delete pSnake;
			pSnake = new Snake(start, end);
			pGrid->AddObjectToCell(pSnake);
			pGrid->GetOutput()->DrawSnake(start, end);
		}
		int NumofCards;
		opendata >> NumofCards;
		for (int i = 0; i < NumofCards; i++)
		{
			int cardnumber, cellnum;
			Card* pCard = NULL;
			opendata >> cardnumber >> cellnum;
			CellPosition cardPosition(cellnum);
			CellPosition non;
			switch (cardnumber)
			{
			case 1:
				int walletAmount;
				opendata >> walletAmount;
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new DecWalletCard_1(cardPosition);
				break;
			case 2:
				int Gamesobjecttype;
				opendata >> Gamesobjecttype;
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new NextCard_2(cardPosition);
				break;
			case 3:
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new BackwardCard_3(cardPosition);
				break;
			case 4:
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new PreventCard_4(cardPosition);
				break;
			case 5:

				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new FireCard_5(cardPosition);
				break;
			case 6:
				int freezeCount;
				bool Evensodds;
				opendata >> freezeCount >> Evensodds;
				pCard = new Card6(cardPosition);
				//pCard->Load(opendata, card, cardPosition, non);
				break;
			case 7:
				static int FeesToPay7;
				static int CardPrice7;
				opendata >> FeesToPay7 >> CardPrice7;
				pCard = new Card7(cardPosition);
				//pCard->Load(opendata, card, cardPosition, non);
				break;
			case 8:
				static int FeesToPay8;
				static int CardPrice8;
				opendata >> FeesToPay8 >> CardPrice8;
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new Card8(cardPosition);
				break;
			case 9:
				static int FeesToPay9;
				static int CardPrice9;
				opendata >> FeesToPay9 >> CardPrice9;
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new Card9(cardPosition);
				break;
			case 10:
				static int FeesToPay10;
				static int CardPrice10;
				opendata >> FeesToPay10 >> CardPrice10;
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new Card10(cardPosition);
				break;
			case 11:
				static int FeesToPay11;
				static int CardPrice11;
				opendata >> FeesToPay11 >> CardPrice11;
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new Card11(cardPosition);
				break;
			case 12:
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new Card12(cardPosition);
				break;
			case 13:
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new Card13(cardPosition);
				break;
			case 14:
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new Card14(cardPosition);
				break;
			case 15:
				int numberofturns;
				opendata >> numberofturns;
				//pCard->Load(opendata, card, cardPosition, non);
				pCard = new Card15(cardPosition);
				break;
			}
			pCard->SetCardNumber(cardnumber);
			pGrid->AddObjectToCell(pCard);
			pGrid->GetOutput()->DrawCell(cardPosition, pCard->GetCardNumber());
		}
		int NumofCoinsets;
		opendata >> NumofCoinsets;
		for (int i = 0; i < NumofCoinsets; i++)
		{
			int cellnum; int amount;
			opendata >> cellnum >> amount;
			CoinSet* pCS = NULL;
			CellPosition coinsetL(cellnum);
			CellPosition non;
			pCS = new CoinSet(coinsetL);
			pCS->SetAmount(amount);
			pGrid->AddObjectToCell(pCS);
			pCS->Draw(pGrid->GetOutput());
		}
		pGrid->GetOutput()->PrintMessage("Data has been loaded");
	}
}