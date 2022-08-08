#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"


class Pawn : public Piece
{
public:
	Pawn(char color) : Piece(color)
	{

	}
	~Pawn()
	{

	}
private:

	 virtual char GetPiece()
	{
		return 'P';

	}

	bool AreSquaresLegal(int, int, int, int, Piece* qboard[8][8]);
};

















#endif 