#ifndef  BISHOP_H
#define BISHOP_H


#include "Piece.h" 



class Bishop : public Piece
{
public:
	Bishop(char color) : Piece(color)
	{

	}
	~Bishop()
	{

	}
private:
	virtual char GetPiece(); 
	bool AreSquaresLegal(int, int, int, int, Piece* qboard[8][8]);

};

















#endif // ! BISHOP_H
