#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "CoinSet.h"
#include "Player.h"
#include "Card7.h"
#include"Card8.h"
#include"Card9.h"
#include"Card10.h"
#include"Card11.h"

Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}
void Grid::SetallCard7(Player* OwnerPlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card7* card7 = dynamic_cast <Card7*> (CellList[i][j]->GetGameObject());
			if (card7) {
				card7->SetOwnerPlayer(OwnerPlayer);
				card7->setmortgaged(FALSE);
			}
		}
	}
}
void Grid::SetallCard8(Player* OwnerPlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card8* card8 = dynamic_cast <Card8*> (CellList[i][j]->GetGameObject());
			if (card8) {
				card8->SetOwnerPlayer(OwnerPlayer);
				card8->setmortgaged(FALSE);
			}
		}
	}
}
void Grid::SetallCard9(Player* OwnerPlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card9* card9 = dynamic_cast <Card9*> (CellList[i][j]->GetGameObject());
			if (card9) {
				card9->SetOwnerPlayer(OwnerPlayer);
				card9->setmortgaged(FALSE);
			}
		}
	}
}
void Grid::SetallCard10(Player* OwnerPlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card10* card10 = dynamic_cast <Card10*> (CellList[i][j]->GetGameObject());
			if (card10) {
				card10->SetOwnerPlayer(OwnerPlayer);
				card10->setmortgaged(FALSE);
			}
		}
	}
}
void Grid::SetallCard11(Player* OwnerPlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card11* card11 = dynamic_cast <Card11*> (CellList[i][j]->GetGameObject());
			if (card11) {
				card11->SetOwnerPlayer(OwnerPlayer);
				card11->setmortgaged(FALSE);
			}
		}
	}
}

void Grid::ReturnOwnership()
{
	Card* pCard7 = GetTheFirstCard7();
	Card* pCard8 = GetTheFirstCard8();
	Card* pCard9 = GetTheFirstCard9();
	Card* pCard10 = GetTheFirstCard10();
	Card* pCard11 = GetTheFirstCard11();
	if (GetTheFirstCard7())
	{
		Card7* FirstCard7 = dynamic_cast <Card7*> (pCard7);
		if (FirstCard7->getChecktoReturnOwnership() == true)
			SetallCard7(getTherealownerofcard7());
	}
	if (GetTheFirstCard8())
	{
		Card8* FirstCard8 = dynamic_cast <Card8*> (pCard8);
		if (FirstCard8->getChecktoReturnOwnership() == true)
			SetallCard8(getTherealownerofcard8());
	}
	if (GetTheFirstCard9())
	{
		Card9* FirstCard9 = dynamic_cast <Card9*> (pCard9);
		if (FirstCard9->getChecktoReturnOwnership() == true)
			SetallCard9(getTherealownerofcard9());
	}
	if (GetTheFirstCard10())
	{
		Card10* FirstCard10 = dynamic_cast <Card10*> (pCard10);
		if (FirstCard10->getChecktoReturnOwnership() == true)
			SetallCard10(getTherealownerofcard10());
	}
	if (GetTheFirstCard11())
	{
		Card11* FirstCard11 = dynamic_cast <Card11*> (pCard11);
		if (FirstCard11->getChecktoReturnOwnership() == true)
			SetallCard8(getTherealownerofcard8());
	}
}
Player* Grid::getTherealownerofcard7()
{
	Card* pcard7 = GetTheFirstCard7();
	Player* x;
	if (GetTheFirstCard7())
	{
		Card7* FirstCard7 = dynamic_cast <Card7*> (pcard7);
		x = FirstCard7->GetTempNonOwner();
	}
	if (x)
		return x;
	else
		return NULL;
}

Player* Grid::getTherealownerofcard8()
{
	Card* pcard8 = GetTheFirstCard8();
	Player* y;
	if (GetTheFirstCard8())
	{
		Card8* FirstCard8 = dynamic_cast <Card8*> (pcard8);
		y = FirstCard8->GetTempNonOwner();
	}
	if (y)
		return y;
	else
		return NULL;
}

Player* Grid::getTherealownerofcard9()
{
	Card* pcard9 = GetTheFirstCard9();
	Player* z;
	if (GetTheFirstCard9())
	{
		Card9* FirstCard9 = dynamic_cast <Card9*> (pcard9);
		z = FirstCard9->GetTempNonOwner();
	}
	if (z)
		return z;
	else
		return NULL;
}

Player* Grid::getTherealownerofcard10()
{
	Card* pcard10 = GetTheFirstCard10();
	Player* l;
	if (GetTheFirstCard10())
	{
		Card10* FirstCard10 = dynamic_cast <Card10*> (pcard10);
		l = FirstCard10->GetTempNonOwner();
	}
	if (l)
		return l;
	else
		return NULL;
}

Player* Grid::getTherealownerofcard11()
{
	Card* pcard11 = GetTheFirstCard11();
	Player* k;
	if (GetTheFirstCard11())
	{
		Card11* FirstCard11 = dynamic_cast <Card11*> (pcard11);
		k = FirstCard11->GetTempNonOwner();
	}
	if (k)
		return k;
	else
		return NULL;
}

// ========= Setters and Getters Functions =========


Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card* pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

void Grid::SetClipboardCS(CoinSet* pcoinset)
{
	ClipboardCS = pcoinset;
}

Card* Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}
CoinSet* Grid::GetClipboardCS() const
{
	return ClipboardCS;
}
void Grid::SetOfferMortgage(OfferMortgage* pOfferMortgage) // to set offer mortgage
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Offer_Accept = pOfferMortgage;
}

OfferMortgage* Grid::GetOfferMortgage()  // to be used in paste
{
	return Offer_Accept;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

Card* Grid::GetTheFirstCard7()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card7* card = dynamic_cast <Card7*> (CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}
Card* Grid::GetTheFirstCard8()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card8* card = dynamic_cast <Card8*> (CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}
Card* Grid::GetTheFirstCard9()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card9* card = dynamic_cast <Card9*> (CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}
Card* Grid::GetTheFirstCard10()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card10* card = dynamic_cast <Card10*> (CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}
Card* Grid::GetTheFirstCard11()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card11* card = dynamic_cast <Card11*> (CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}
// ========= Other Getters =========


Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Cell* Grid::GetCell(const CellPosition c)
{
	return CellList[c.VCell()][c.HCell()];
}

Ladder* Grid::GetNextLadder(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasLadder() != NULL)
				return CellList[i][j]->HasLadder();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
Snake* Grid::GetNextSnake(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the Snake in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasSnake() != NULL)
				return CellList[i][j]->HasSnake();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
CoinSet* Grid::GetNextCoinSet(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the Snake in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasCoinSet() != NULL)
				return CellList[i][j]->HasCoinSet();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
Card* Grid::GetNextCard(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the Card in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a Card, if yes return it
			if (CellList[i][j]->HasCard() != NULL)
				return CellList[i][j]->HasCard();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
Ladder* Grid::GetPreviousLadder(const CellPosition& position)
{
	for (int i = NumVerticalCells - 1; i >= position.VCell(); i--) // searching from 1st Vcell and ABOVE
	{
		if (i != position.VCell())
		{
			for (int j = 0; j < NumHorizontalCells; j++) // searching from 1st horizontal and RIGHT till last Hcell
			{
				///TODO: Check if CellList[i][j] has a ladder, if yes return it
				if (CellList[i][j]->HasLadder())
					return CellList[i][j]->HasLadder();
			}
		}
		else
		{
			for (int j = 0; j <= position.HCell(); j++) // searching from 1st horizontal and RIGHT to current Hcell
			{
				///TODO: Check if CellList[i][j] has a ladder, if yes return it
				if (CellList[i][j]->HasLadder())
					return CellList[i][j]->HasLadder();
			}
		}
	}
	return NULL; // not found
}
Snake* Grid::GetPreviousSnake(const CellPosition& position)
{
	for (int i = NumVerticalCells - 1; i >= position.VCell(); i--) // searching from 1st Vcell and ABOVE
	{
		if (i != position.VCell())
		{
			for (int j = 0; j < NumHorizontalCells; j++) // searching from 1st horizontal and RIGHT till last Hcell
			{
				///TODO: Check if CellList[i][j] has a Snake, if yes return it
				if (CellList[i][j]->HasSnake())
					return CellList[i][j]->HasSnake();
			}
		}
		else
		{
			for (int j = 0; j <= position.HCell(); j++) // searching from 1st horizontal and RIGHT to current Hcell
			{
				///TODO: Check if CellList[i][j] has a Snake, if yes return it
				if (CellList[i][j]->HasSnake())
					return CellList[i][j]->HasSnake();
			}
		}
	}
	return NULL; // not found
}
CoinSet* Grid::GetPreviousCoinSet(const CellPosition& position)
{

	for (int i = NumVerticalCells - 1; i >= position.VCell(); i--) // searching from 1st Vcell and ABOVE
	{
		if (i != position.VCell())
		{
			for (int j = 0; j < NumHorizontalCells; j++) // searching from 1st horizontal and RIGHT till last Hcell
			{
				///TODO: Check if CellList[i][j] has a CoinSet, if yes return it
				if (CellList[i][j]->HasCoinSet())
					return CellList[i][j]->HasCoinSet();
			}
		}
		else
		{
			for (int j = 0; j <= position.HCell(); j++) // searching from 1st horizontal and RIGHT to current Hcell
			{
				///TODO: Check if CellList[i][j] has a CoinSet, if yes return it
				if (CellList[i][j]->HasCoinSet())
					return CellList[i][j]->HasCoinSet();
			}
		}
	}
	return NULL; // not found
}
Card* Grid::GetPreviousCard(const CellPosition& position)
{

	for (int i = NumVerticalCells - 1; i >= position.VCell(); i--) // searching from 1st Vcell and ABOVE
	{
		if (i != position.VCell())
		{
			for (int j = 0; j < NumHorizontalCells; j++) // searching from 1st horizontal and RIGHT till last Hcell
			{
				///TODO: Check if CellList[i][j] has a Card, if yes return it
				if (CellList[i][j]->HasCard())
					return CellList[i][j]->HasCard();
			}
		}
		else
		{
			for (int j = 0; j <= position.HCell(); j++) // searching from 1st horizontal and RIGHT to current Hcell
			{
				///TODO: Check if CellList[i][j] has a Card, if yes return it
				if (CellList[i][j]->HasCard())
					return CellList[i][j]->HasCard();
			}
		}
	}
	return NULL; // not found
}

// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnakeOrCoinSet(pOut);
			}
		}


		///TODO: Add the code that draws the CoinSet game objects

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}
void Grid::SaveAll(ofstream& Output, Type Type) const
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			GameObject* pGopject = CellList[i][j]->GetGameObject();
			if (pGopject != NULL)
				pGopject->Save(Output, Type);
		}
	}

}

int Grid::Numofladders()
{
	int count = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			Ladder* pLadder = CellList[i][j]->HasLadder();
			if (pLadder != NULL) {
				if (pLadder->GetEndPosition().GetCellNum() == -1) {
					return count;
			   } 
				else{ count++; }
			}
		}
	}
	return count;
}
int Grid::Numofsnakes()
{
	int count = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			Snake* pSnake = CellList[i][j]->HasSnake();
			if (pSnake != NULL){
				count++;
				if (pSnake->GetEndPosition().GetCellNum() == -1)
					count--;
			}		
		}
	}
	return count;
}
int Grid::Numofcards()
{
	int count = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			Card* pCard = CellList[i][j]->HasCard();
			if (pCard != NULL)
				count++;
		}
	}
	return count;
}
int Grid::Numofcoinsset()
{
	int count = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			CoinSet* pCoinset = CellList[i][j]->HasCoinSet();
			if (pCoinset != NULL)
				count++;
		}
	}
	return count;
}
void Grid::DeleteAll()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			GameObject* pGopject = CellList[i][j]->GetGameObject();
			if (pGopject != NULL)
				RemoveObjectFromCell(pGopject->GetPosition());
		}
	}
}

Player*Grid::Check_Winner()
{
	int max = -99999;
	int maxi;
	int maxSteps;
	int check = -9999;
	int checki;
	
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (PlayerList[i]->GetWallet() > max)
		{
			max = PlayerList[i]->GetWallet();
			maxi = i;
		}
	}

	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (maxi != i)
		{
			if (PlayerList[i]->GetWallet() == max)
			{
				if (PlayerList[i]->GetstepCount() > PlayerList[maxi]->GetstepCount())
				{
					maxi = i;
					max = PlayerList[i]->GetWallet();
				}
			}
		}
	}

	return PlayerList[maxi];
}

void Grid::Reset()
{
	Card* card;
	Card7* card7;
	Card8* card8;
	Card9* card9;
	Card10* card10;
	Card11* card11;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i]->setStepCount(0);
		PlayerList[i]->SetWallet(100);
		UpdatePlayerCell(PlayerList[i], PlayerList[i]->GetstepCount()+1);
		PlayerList[i]->SetTurnCount(0);
		PlayerList[i]->setFreezeCount(0);
		PlayerList[i]->setNumberOfBenefitSwitchTurns(0);
	}
	currPlayerNumber=0;
	card =GetTheFirstCard7();
	card7 = dynamic_cast<Card7*>(card);
	if (card7) {
		card7->SetMortagePlayer(NULL);
		card7->SetOwnerPlayer(NULL);
		card7->setmortgaged(false);
	}
	card = GetTheFirstCard8();
	card8 = dynamic_cast<Card8*>(card);
	if (card8) {
		card8->SetMortagePlayer(NULL);
		card8->SetOwnerPlayer(NULL);
		card8->setmortgaged(false);
	}
	card = GetTheFirstCard9();
	card9 = dynamic_cast<Card9*>(card);
	if (card9) {
		card9->SetMortagePlayer(NULL);
		card9->SetOwnerPlayer(NULL);
		card9->setmortgaged(false);
	}
	card = GetTheFirstCard10();
	card10 = dynamic_cast<Card10*>(card);
	if (card10) {
		card10->SetMortagePlayer(NULL);
		card10->SetOwnerPlayer(NULL);
		card10->setmortgaged(false);
	}
	card = GetTheFirstCard11();
	card11 = dynamic_cast<Card11*>(card);
	if (card11) {
		card11->SetMortagePlayer(NULL);
		card11->SetOwnerPlayer(NULL);
		card11->setmortgaged(false);
	}
}
void Grid::SetSemiCard7(Player* MortagePlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card7* card7 = dynamic_cast <Card7*> (CellList[i][j]->GetGameObject());
			if (card7) {
				card7->SetMortagePlayer(MortagePlayer);
				card7->setmortgaged(TRUE);
			}
		}
	}
}
void Grid::SetSemiCard8(Player* MortagePlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card8* card8 = dynamic_cast <Card8*> (CellList[i][j]->GetGameObject());
			if (card8) {
				card8->SetMortagePlayer(MortagePlayer);
				card8->setmortgaged(TRUE);
			}
		}
	}
}void Grid::SetSemiCard9(Player* MortagePlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card9* card9 = dynamic_cast <Card9*> (CellList[i][j]->GetGameObject());
			if (card9) {
				card9->SetMortagePlayer(MortagePlayer);
				card9->setmortgaged(TRUE);
			}
		}
	}
}void Grid::SetSemiCard10(Player* MortagePlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card10* card10 = dynamic_cast <Card10*> (CellList[i][j]->GetGameObject());
			if (card10) {
				card10->SetMortagePlayer(MortagePlayer);
				card10->setmortgaged(TRUE);
			}
		}
	}
}void Grid::SetSemiCard11(Player* MortagePlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			Card11* card11 = dynamic_cast <Card11*> (CellList[i][j]->GetGameObject());
			if (card11) {
				card11->SetMortagePlayer(MortagePlayer);
				card11->setmortgaged(TRUE);
			}
		}
	}
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}