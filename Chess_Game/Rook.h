#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(char color) : Piece(color)
	{

	}

	~Rook()
	{

	}


private:
	char GetPiece(); 

	bool AreSquaresLegal(int, int, int, int, Piece* qboard[8][8]);


};

























#endif