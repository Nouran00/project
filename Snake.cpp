#include "Snake.h"
#include "Player.h"
Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos), ObjectType(snake)
{
	if (startCellPos.VCell() < endCellPos.VCell() && startCellPos.HCell() == endCellPos.HCell())
		this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	int x, y;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	Input* pIn = pGrid->GetInput();
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// 2- Apply the Snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	GameObject* gameObject = pPlayer->GetCell()->GetGameObject();
	if (gameObject != NULL)
		gameObject->Apply(pGrid, pPlayer);

	if (pPlayer->GetstepCount() == NumHorizontalCells * NumVerticalCells)
	{
		pGrid->SetEndGame(true);
	}

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& OutFile, Type Type)
{
	if (Type == ObjectType)
	{
		CellPosition temp;
		temp = GetPosition();
		if (endCellPos.GetCellNum() == -1) {
			return;
		}
		else {
			OutFile << temp.GetCellNum() << "\t" << endCellPos.GetCellNum() << endl;
		}
	}
	else { return; }
}

void Snake::Load(ifstream& Infile, Type Type, CellPosition& starts, CellPosition& ends)
{
	if (Type == snake)
	{

		int start, end;
		Infile >> start >> end;
		CellPosition temp(start);
		CellPosition temp1(end);
		ends.SetHCell(temp1.HCell());
		ends.SetVCell(temp1.VCell());
		starts.SetHCell(temp.HCell());
		starts.SetVCell(temp.VCell());

	}
}

Snake::~Snake()
{
}