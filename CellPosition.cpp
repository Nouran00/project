#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v <= NumVerticalCells -1)
	{
		vCell = v;
		return true;
	}
	else
	{
		return false; // this line sould be changed with your implementation
	}

	 // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h <= NumHorizontalCells -1)
	{
		hCell = h;
		return true;
	}
	else
	{
	return false; 
	}

	// this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if (vCell <= NumVerticalCells-1 && vCell >= 0 && hCell >= 0 && hCell <= NumHorizontalCells-1) 
		return true;
	else 
		return false;
	 // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	if (cellPosition.IsValidCell() == true)
	{
		int h = cellPosition.HCell();
		int v = cellPosition.VCell();
		v = NumVerticalCells - 1 - v;
		int cellnum = 0;
		cellnum = (NumHorizontalCells * v) + 1 + h;
		return cellnum;	
	} 
	// this line should be changed with your implementation
	else return -1;// Inavalid cell
	

	 // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	
	CellPosition position;
	
	if (cellNum > NumHorizontalCells* NumVerticalCells || cellNum < 0) 
	{
		return position;
	}
	else
	{
		int v = 0, h = 0;
			for (int i = 0; i <= (NumVerticalCells - 1); i++)
			{
				if ((cellNum >= ((NumHorizontalCells * i) + 1)) && (cellNum <= (NumHorizontalCells + (NumHorizontalCells * i))))
				{
					v = i;
					h = cellNum - (NumHorizontalCells * i + 1);
					v = NumVerticalCells - 1 - v;
					break;
				}

			}
			position.SetHCell(h);
			position.SetVCell(v);
			return position;
	}
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it

}

void CellPosition::AddCellNum (int addedNum)
{
	
	/// TODO: Implement this function as described in the .h file
	int cellnum = GetCellNum();
	cellnum += addedNum;
	if (cellnum > 99)
	{
		cellnum = 99;
	}
	if (cellnum <1)
	{
		cellnum=1;
	}
	CellPosition c1= GetCellPositionFromNum(cellnum);
	hCell=(c1.HCell());
	vCell=(c1.VCell());


	// Note: this function updates the data members (vCell and hCell) of the calling object

}