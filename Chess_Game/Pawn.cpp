

#include "Pawn.h"



bool Pawn::AreSquaresLegal(int srcRow, int srcCol, int desRow, int desCol, Piece* qboard[8][8])
{
	Piece* pDest = qboard[desRow][desCol];
	if (pDest == 0)
	{
		if (srcCol == desCol)
		{
			if (GetColor() == 'W')
			{
				if (desRow == srcRow + 1)
					return true;
			}
			else
			{
				if (desRow = srcRow - 1)
					return true;
			}
		}
	}
	else
	{
		// it holds the opposite color
		if ((srcCol == desCol + 1) || (srcCol == desCol - 1))
		{
			if (GetColor() == 'W')
			{
				if (desRow == srcRow + 1)
				{
					return true;
				}
			}
			else
			{
				if (desRow == srcRow - 1)
				{
					return true;
				}
			}


		}

	}
	return false;
}

