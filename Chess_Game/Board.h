#ifndef  BOARD_H
#define  BOARD_H
#include <memory>
#include <iostream>


#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"


class Board
{
public:
	Board()
	{
		for (int row = 0; row < 8; row++)
			for (int col = 0; col < 8; col++)
				pieceBoard[row][col] = 0; 

		// allocating pieces 
		for (int col = 0; col < 8; col++)
			pieceBoard[1][col] = new Pawn('W'); 

		pieceBoard[0][0] = new Rook('W'); 
		pieceBoard[0][1] = new Knight('W');
		pieceBoard[0][2] = new Bishop('W');
		pieceBoard[0][3] = new King('W');
		pieceBoard[0][4] = new Queen('W');
		pieceBoard[0][5] = new Bishop('W');
		pieceBoard[0][6] = new Knight('W');
		pieceBoard[0][7] = new Rook('W');


		// black pieces
		for (int col = 0; col < 8; col++)
			pieceBoard[6][col] = new Pawn('B'); 


		pieceBoard[7][0] = new Rook('W');
		pieceBoard[7][1] = new Knight('W');
		pieceBoard[7][2] = new Bishop('W');
		pieceBoard[7][3] = new King('W');
		pieceBoard[7][4] = new Queen('W');
		pieceBoard[7][5] = new Bishop('W');
		pieceBoard[7][6] = new Knight('W');
		pieceBoard[7][7] = new Rook('W');

	}

	~Board()
	{
		for(int row = 0; row < 8; row++)
			for (int col = 0; col < 8; col++)
			{
				delete pieceBoard[row][col]; 
				pieceBoard[row][col] = 0; 
			}
	}

	void Print()
	{
		using namespace std; 
		const int SquareWidth = 4;
		const int SquareHeight = 3;
		for (int row = 0; row < 8 * SquareHeight; ++row) {
			int SquareRow = row / SquareHeight;
			// Print side border with numbering
			if (row % 3 == 1) {
				cout << '-' << (char)('1' + 7 - SquareRow) << '-';
			}
			else {
				cout << "---";
			}

			// Print the chess board
			for (int col = 0; col < 8 * SquareWidth; ++col) {
				int SquareCol = col / SquareWidth;
				if (((row % 3) == 1) && ((col % 4) == 1 || (col % 4) == 2) && pieceBoard[7 - SquareRow][SquareCol] != 0) {
					if ((col % 4) == 1) {
						cout << pieceBoard[7 - SquareRow][SquareCol]->GetColor();
					}
					else {
						cout << pieceBoard[7 - SquareRow][SquareCol]->GetPiece();
					}
				}
				else {
					if ((SquareRow + SquareCol) % 2 == 1) {
						cout << '*';
					}
					else {
						cout << ' ';
					}
				}
			}
			cout << endl;
		}

		
		for (int row = 0; row < SquareHeight; ++row) {
			if (row % 3 == 1) {
				cout << "---";
				for (int col = 0; col < 8 * SquareWidth; ++col) {
					int SquareCol = col / SquareWidth;
					if ((col % 4) == 1) {
						cout << (SquareCol + 1);
					}
					else {
						cout << '-';
					}
				}
				cout << endl;
			}
			else {
				for (int col = 1; col < 9 * SquareWidth; ++col) {
					cout << '-';
				}
				cout << endl;
			}
		}

	}


	bool isCheck(char color)
	{
		int kingRow; 
		int kingCol; 
		for (int row = 0; row < 8; row++)
		{
			for (int col = 0; col < 8; col++)
			{
				if (pieceBoard[row][col] != 0)
				{
					if (pieceBoard[row][col]->GetColor() == color)
					{
						if (pieceBoard[row][col]->GetPiece() == 'K')
						{
							kingRow = row; 
							kingCol = col; 
						}

					}
				}
			}
		}

		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				if (pieceBoard[row][col] != 0) {
					if (pieceBoard[row][col]->GetColor() != color) {
						if (pieceBoard[row][col]->IsLegalMove(row, col, kingRow, kingCol, pieceBoard)) {
							return true;
						}
					}
				}
			}
		}

		return false; 


	}

	bool canMove(char color)
	{
		for (int row = 0; row < 8; row++)
		{
			for (int col = 0; col < 8; col++)
			{
				if (pieceBoard[row][col] != 0)
				{
					if (pieceBoard[row][col]->GetColor() == color)
					{
						for (int desRow = 0; desRow < 8; desRow++)
						{
							for (int desCol = 0; desCol < 8; desCol++)
							{
								if (pieceBoard[row][col]->IsLegalMove(row, col, desRow, desCol, pieceBoard))
								{
									Piece* pTemp = pieceBoard[desRow][desCol]; 
									pieceBoard[desRow][desCol] = pieceBoard[row][col]; 
									pieceBoard[row][col] = 0; 

									bool canmove = !isCheck(color); 
									pieceBoard[row][col] = pieceBoard[desRow][desCol];
									pieceBoard[desRow][desCol] = pTemp; 

									if (canmove)
										return true; 




								}

							}

						}


					}


				}
			}


		}
		return false; 

	}


private:

	Piece* pieceBoard[8][8]; 
};
#endif // ! BOARD_H
