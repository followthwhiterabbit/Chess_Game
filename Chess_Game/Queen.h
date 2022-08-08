#ifndef QUEEN_H
#define QUEEN_H


#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(char); 

	~Queen(); 

private:
	bool AreSquaresLegal(int, int, int, int, Piece* qboard[8][8]); 

	char GetPiece(); 

};


	


















#endif