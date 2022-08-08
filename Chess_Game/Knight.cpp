#include "Knight.h"



Knight::Knight(char color) : Piece(color) 
{

}

Knight::~Knight()
{

}



bool Knight::AreSquaresLegal(int srcRow, int srcCol, int desRow, int desCol, Piece* qboard[8][8])
{
	if ((srcCol == desCol + 1) || (srcRow == desCol - 1))
	{
		if ((srcRow == desRow + 2) || (srcRow == desCol - 2))
			return true;
	}

	if ((srcCol == desCol + 2) || (srcCol == desCol - 2))
		if ((srcRow == desCol + 1) || (srcRow == desCol - 1))
			return true;

	return false;

}



