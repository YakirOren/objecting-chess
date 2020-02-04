#include "Rook.h"

Rook::Rook(int x, int y, int color) : Piece(color, x, y, rook)
{


}

bool Rook::canMoveTo(Board board, int dstX, int dstY)
{
	bool canMove = true;
	if ((dstX == this->getX() && dstY != this->getY()) || (dstY == this->getY() && dstX != this->getX())) {
		for (int i = this->getY() + 1; i <= dstY; i++)
		{
			if (board(this->getX(), i) != nullptr)
			{
				canMove = false;
			}
		}
		for (int i = this->getY() - 1; i >= dstY; i--)
		{
			if (board(this->getX(), i) != nullptr)
			{
				canMove = false;
			}
		}
		for (int i = this->getX() + 1; i <= dstX; i++)
		{
			if (board(i, this->getY()) != nullptr)
			{
				canMove = false;
			}
		}
		for (int i = this->getX() - 1; i >= dstX; i--)
		{
			if (board(i, this->getY()) != nullptr)
			{
				canMove = false;
			}
		}
	}

	return canMove;
}

bool Rook::isCheck(Board board) const
{
	bool check = false;
	std::vector<char>* threats = this->isThreatening(board);
	for (int i = 0; i < threats->size(); i++)
	{
		if (tolower((*threats)[i]) == king)
		{
			check = true;
		}
	}

	return check;
}

std::vector<char>* Rook::isThreatening(Board board) const
{
	std::vector<char>* threats = new std::vector<char>;
	for (int i = this->getY() + 1; i <= BOARD_SIZE; i++)
	{
		if (board(this->getX(), i) != nullptr)
		{
			if (board(this->getX(), i)->getColor() == board(this->getX(), this->getY())->getColor())
			{
				threats->push_back(board(this->getX(), i)->getSymbol());
				break;
			}
		}
	}
	for (int i = this->getY() - 1; i >= BOARD_SIZE; i--)
	{
		if (board(this->getX(), i) != nullptr)
		{
			if (board(this->getX(), i)->getColor() == board(this->getX(), this->getY())->getColor())
			{
				threats->push_back(board(this->getX(), i)->getSymbol());
				break;
			}
		}
	}
	for (int i = this->getX() + 1; i <= BOARD_SIZE; i++)
	{
		if (board(i, this->getY()) != nullptr)
		{
			if (board(i, this->getY())->getColor() == board(this->getX(), this->getY())->getColor())
			{
				threats->push_back(board(i, this->getY())->getSymbol());
				break;
			}
		}
	}
	for (int i = this->getX() - 1; i >= BOARD_SIZE; i--)
	{
		if (board(i, this->getY()) != nullptr)
		{
			if (board(i, this->getY())->getColor() == board(this->getX(), this->getY())->getColor())
			{
				threats->push_back(board(i, this->getY())->getSymbol());
				break;
			}
		}
	}
	return threats;
}

Rook::~Rook()
{

}


