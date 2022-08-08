#include "Bishop.h"

char Bishop::GetPiece()
{
	return 'B'; 
}

bool Bishop::AreSquaresLegal(int srcRow, int srcCol, int desRow, int desCol, Piece* qboard[8][8])
{
	if ((desCol - srcCol == desRow - srcRow) || (desCol - srcCol == srcRow - desRow))
	{
		int rowOffset = (desRow - srcRow > 0) ? 1 : -1; 
		int colOffset = (desCol - srcCol > 0) ? 1 : -1; 
		int checkRow; 
		int checkCol; 
		for (checkRow = srcRow + rowOffset, checkCol = srcCol + colOffset;
			checkRow != desRow;
			checkRow = checkRow + rowOffset, checkCol = checkCol + colOffset)
		{
			if (qboard[checkRow][checkCol] != 0)
				return false; 
		}
		return true; 

	}
	return false; 





}
