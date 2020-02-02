#include "Rook.h"

Rook::Rook(int x, int y, int color) : Piece(color, x, y, rook)
{
	
	
}

bool Rook::canMoveTo(Piece*** board, int dstX, int dstY)
{
	bool canMove = true;
	if ((dstX == this->getX() && dstY != this->getY()) || (dstY == this->getY() && dstX != this->getX())) {
		for (int i = this->getY() + 1; i <= dstY; i++)
		{
			if (board[this->getX()][i] != nullptr)
			{
				canMove = false;
			}
		}
		for (int i = this->getX() + 1; i <= dstX; i++)
		{
			if (board[i][this->getY()] != nullptr)
			{
				canMove = false;
			}
		}
	}

	

	return canMove;
}

bool Rook::isCheck() const
{
	


	return false;
}

std::vector<char>* Rook::isThreatening() const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

Rook::~Rook()
{

}


