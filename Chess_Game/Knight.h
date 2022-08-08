#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{

public:
	Knight(char);
	~Knight();
	


private:
	virtual char GetPiece()
	{
		return 'N'; 
	}

	bool AreSquaresLegal(int, int, int, int, Piece* qboard[8][8]);
};




















#endif 
