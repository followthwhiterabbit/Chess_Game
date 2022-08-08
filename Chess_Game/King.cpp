#include "King.h"



char King::getPiece()
{
	return 'K';
}




bool King::AreSquaresLegal(int srcRow, int srcCol, int desRow, int desCol, Piece* qboard[8][8])
{
	int	rowDelta = desRow - srcRow; 
	int colDelta = desCol - srcCol; 

	if (((rowDelta >= -1) && (rowDelta <= 1)) && ((colDelta >= -1) && (colDelta <= 1)))
		return true; 
	return false; 



}


