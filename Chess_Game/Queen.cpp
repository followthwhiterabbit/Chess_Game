#include "Queen.h"


Queen::Queen(char color) : Piece(color)
{

}





char Queen::getPiece()
{
	return 'Q';
}


bool Queen::AreSquaresLegal(int srcRow, int srcCol, int desRow, int desCol, Piece* qboard[8][8])
{
	if (srcRow == desRow)
	{
		int colOffset = (desCol - srcCol > 0) ? 1 : -1;
		for (int checkCol = srcCol + colOffset; checkCol != desCol; checkCol = checkCol + colOffset)
			if (qboard[srcRow][srcCol] != 0)
				return false;
		return true;

	}
	else if (desCol == srcCol)
	{
		int rowOffset = (desRow - srcRow > 0) ? 1 : -1;
		for (int checkRow = srcRow + rowOffset; checkRow != desRow; checkRow = checkRow = rowOffset)
			if (qboard[srcRow][srcCol] != 0)
				return false;
		return true;

	}
	else if ((desCol - srcCol == desRow - srcRow) || (desCol - srcCol == srcRow - desRow))
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


