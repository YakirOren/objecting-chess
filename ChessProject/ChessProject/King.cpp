#include "King.h"
#include "chessUtills.h"


King::King(const int& x, const int& y, const int& color) : Piece(color, x, y, king) {

}


King::~King()
{
}

int King::canMoveTo(Board& board, const int& dstX, const int& dstY) const
{
	int canMove = no_invalid;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if ((i == 0) && (j == 0))
			{
				continue;
			}
			else if (((this->getX() + i) == dstX) && ((this->getY() + j) == dstY)) {
				canMove = yes_valid;
			}
		}
	}

	if (canMove == yes_valid)
	{
		int ogX = this->getX();
		int ogY = this->getY();
		Piece* pieceInDst = board(dstX, dstY); //TODO fix this, the linkage after seeing check will not link the original piece in the dst

		board.updateBoard(this->getX(), this->getY(), dstX, dstY); //moving to the dst 
		// if the king is threathed in the new pos we need to take him back to the orignal pos
		bool isThreat = chessUtills::isThereCheckForColor(this->getColor(), board);// checking if the king is being threatend in the new pos
		if (isThreat)
		{
			board.updateBoard(dstX, dstY, ogX, ogY); //moving from the dst back to the og pos 

			board.updateBoard(pieceInDst->getX(), pieceInDst->getY(), dstX, dstY); // moving the orignal piece to its orignal postion

			canMove = no_invalid_will_chess_you;

		}


	}


	return canMove;
}

std::vector<char>* King::isThreatening(Board& board) const
{
	std::vector<char>* temp = new std::vector<char>;

	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if ((i == 0) && (j == 0))
			{
				continue;
			}
			else if (board((this->getX() + i), (this->getY() + j)) != nullptr) {
				temp->push_back(board((this->getX() + i), (this->getY() + j))->getSymbol());
			}
		}
	}


	return temp;
}
