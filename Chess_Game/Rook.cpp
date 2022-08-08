#include "Rook.h"


char Rook::GetPiece()
{
	return 'R';
}


bool Rook::AreSquaresLegal(int srcRow, int srcCol, int desRow, int desCol, Piece* qboard[8][8])
{
	if (srcRow == desRow)
	{
		int colOffset = (desCol - srcCol > 0) ? 1 : -1; 
		for (int checkCol = srcCol + colOffset; checkCol != desCol; checkCol = checkCol + colOffset)
			if (qboard[srcRow][srcCol] != 0)
				return false; 
		return true; 
	
	}
	else if(desCol == srcCol)
	{
		int rowOffset = (desRow - srcRow > 0) ? 1 : -1; 
		for (int checkRow = srcRow + rowOffset; checkRow != desRow; checkRow = checkRow = rowOffset)
			if (qboard[srcRow][srcCol] != 0)
				return false; 
		return true; 

	}
	return false; 


}
