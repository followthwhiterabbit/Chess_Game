#ifndef KING_H
#define KING_H

#include "Piece.h"


class King : public Piece
{
public:

	King(char color) : Piece(color)
	{

	}

	~King()
	{

	}

private:
	char GetPiece(); 

	bool AreSquaresLegal(int, int, int, int, Piece* qboard[8][8]); 

};



















#endif // !KING_H

