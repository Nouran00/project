#include "PasteAction.h"
#include"Grid.h"
#include"BackwardCard_3.h"
#include"Card10.h"
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

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void PasteAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Grid* cGrid = pManager->GetGrid();

	pOut->ClearStatusBar();
}

void PasteAction::Execute()
{
	ReadActionParameters();
	bool t;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	CoinSet* cpdSet;
	Card* cpdCard;
	pOut->PrintMessage("Paste The Card/Coin Set... Click on the needed cell");
	Cell Cell1(pIn->GetCellClicked());
	Card* ClickedCard = pGrid->GetClipboard();
	CoinSet* ClickedSet = pGrid->GetClipboardCS();
	if (ClickedSet != NULL) {
		cpdSet = new CoinSet(Cell1.GetCellPosition());
		int amount = ClickedSet->GetAmount();
		t = pGrid->AddObjectToCell(cpdSet);
	}
	else {
		int cnum = ClickedCard->GetCardNumber();
		switch (cnum)
		{
		case 1:
		{
			DecWalletCard_1* C1 = (DecWalletCard_1*)ClickedCard;
			cpdCard = new DecWalletCard_1(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(1);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		}
		case 2:
		{
			NextCard_2* C2 = (NextCard_2*)ClickedCard;
			cpdCard = new NextCard_2(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(2);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		}
		case 3:
			cpdCard = new BackwardCard_3(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(3);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 4:
			cpdCard = new PreventCard_4(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(4);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 5:
			cpdCard = new FireCard_5(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(5);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 6:
			cpdCard = new Card6(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(6);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 7:
			cpdCard = new Card7(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(7);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 8:
			cpdCard = new Card8(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(8);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 9:
			cpdCard = new Card9(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(9);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 10:
			cpdCard = new Card10(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(10);
			t = pGrid->AddObjectToCell(cpdCard);
		case 11:
			cpdCard = new Card11(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(11);
			t = pGrid->AddObjectToCell(cpdCard);
		case 12:
			cpdCard = new Card12(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(12);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 13:
			cpdCard = new Card13(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(13);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 14:
			cpdCard = new Card14(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(14);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		case 15:
			cpdCard = new Card15(Cell1.GetCellPosition());
			cpdCard->SetCardNumber(15);
			t = pGrid->AddObjectToCell(cpdCard);
			break;
		}
	}
	if (!t)
		pGrid->PrintErrorMessage("Error!!This cell already has a game object!,Click to continue");
	pOut->ClearStatusBar();
}


PasteAction::~PasteAction()
{
}
