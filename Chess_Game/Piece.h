#ifndef PIECE_H
#define PIECE_H


class Piece
{
public:
	Piece(char color) : cColor(color)
	{

	}

	~Piece()
	{

	}

	virtual char GetPiece() = 0; 

	char GetColor()
	{
		return cColor;
	}
	
	bool IsLegalMove(int srcRow, int srcCol, int desRow, int desCol, Piece* qboard[8][8])
	{
		Piece* pDest = qboard[desRow][desCol];

		if ((pDest == 0) || (cColor != pDest->GetColor()))
			return AreSquaresLegal(srcRow, srcCol, desRow, desCol, qboard);
		return false;

	}

private:
	virtual bool AreSquaresLegal(int, int, int, int, Piece* qboard[8][8]) = 0;
	char cColor; 

};

#endif