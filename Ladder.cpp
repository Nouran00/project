#include "Ladder.h"
#include "Player.h"
Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos), ObjectType(ladder)
{
	if (startCellPos.VCell() > endCellPos.VCell() && startCellPos.HCell() == endCellPos.HCell())
		this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	int x, y;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	Input* pIn = pGrid->GetInput();
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
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

void Ladder::Save(ofstream& OutFile, Type Type)
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

void Ladder::Load(ifstream& Infile, Type Type, CellPosition& start2, CellPosition& end2)
{
	if (Type == ladder)
	{

		int start, end;
		Infile >> start >> end;
		CellPosition temp(start);
		CellPosition temp1(end);
		end2.SetHCell(temp1.HCell());
		end2.SetVCell(temp1.VCell());
		start2.SetHCell(temp.HCell());
		start2.SetVCell(temp.VCell());

	}
}


CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
