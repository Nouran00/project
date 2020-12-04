#include "Player.h"
#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	freezecount = 0;
	NumberOfBenefitSwitchTurns = 0;
	BenefitSwitched = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======
int Player::getFreezeCount()
{
	return freezecount;
}
void Player::setNumberOfBenefitSwitchTurns(int y) {
	NumberOfBenefitSwitchTurns = y;
}
int Player::getNumberOfBenefitSwitchTurns() {
	return NumberOfBenefitSwitchTurns;
}
void Player::setFreezeCount(int x)
{
	freezecount = x;
}

void Player::setStepCount(int v)
{
	stepCount = v;
}

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}
void Player::SetDontMove(bool DontMove)
{
	this->DontMove = DontMove;
}

int Player::GetWallet() const
{
	return wallet;
}

void Player::SetTurnCount(int v)
{
	turnCount = v;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
int Player::GetjustRolledDiceNum() const
{
	return justRolledDiceNum;
}
int Player::GetstepCount() const
{
	return stepCount;
}

int Player::getPlayerNum()
{
	return playerNum;
}
void Player::setOorEPrevented(int y)
{
	OorEPrevented = y;
}
int Player::getOorEPrevented()
{
	return OorEPrevented;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	//Output* pOut=pGrid->GetOutput();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	turnCount++;

	if (getNumberOfBenefitSwitchTurns() != 0)
	{
		if (BenefitSwitched == false)
		{
			BenefitSwitched = true;
		}
		NumberOfBenefitSwitchTurns--;
	}

	if (getNumberOfBenefitSwitchTurns() == 0 && BenefitSwitched == true)
	{
		BenefitSwitched = false;
		pGrid->ReturnOwnership();
		pGrid->PrintErrorMessage("BenefitSwitch ended, all cities returned to their owners , click to continue");
	}

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (getFreezeCount() > 0)
	{
		if (getOorEPrevented() == 0)
		{
			freezecount--;
			pGrid->PrintErrorMessage(" Freezed , No movement because you are in even cell ");
			return;
		}
		if (getOorEPrevented() == 1)
		{
			freezecount--;
			pGrid->PrintErrorMessage(" Freezed , No movement because you are in odd cell ");
			return;
		}
	}

	if (turnCount == 3)
	{
		wallet = wallet + diceNumber * 10;
		turnCount = 0;
		pGrid->PrintErrorMessage(" no movement, wallet recharged by " + to_string(diceNumber * 10));
		return;
	}
	if (DontMove == true)
	{
		pGrid->PrintErrorMessage(" prevented from movement ...click to continue ");
		DontMove = false;
		return;
	}
	if (wallet > 0)
	{
		// 3- Set the justRolledDiceNum with the passed diceNumber
		justRolledDiceNum = diceNumber;
		// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
		//    Using the appropriate function of CellPosition class to update "pos"
		CellPosition pos = pCell->GetCellPosition();
		pos.AddCellNum(diceNumber);
		if (pos.IsValidCell())
		{
			// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
			//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
			pGrid->UpdatePlayerCell(this, pos);
			stepCount = pos.GetCellNum();
			// 6- Apply() the game object of the reached cell (if any)
			GameObject* gameObject = pCell->GetGameObject();
			if (gameObject != NULL)
				gameObject->Apply(pGrid, this);
			// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
			if (stepCount == 99)
			{
				pGrid->SetEndGame(true);
			}
		}
		else pGrid->PrintErrorMessage("the player will exceed the no. of cells ... Click to contiune");
	}
	else pGrid->PrintErrorMessage("player has no enough money in the wallet to enable movement... wait till recharge");
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
