#include "Rook.h"

Rook::Rook(const int& x, const int& y, const int& color) : Piece(color, x, y, rook)
{


}

int Rook::canMoveTo(Board& board, const int& dstX, const int& dstY) const
{
	//TODO check if the king will be in check after move ad return acordingly
	if ((dstX == this->getX() && dstY != this->getY()) || (dstY == this->getY() && dstX != this->getX())) {
		for (int i = this->getY() + 1; i < dstY; i++)
		{
			if (board(this->getX(), i) != nullptr)
			{
				return no_invalid;
			}
		}
		for (int i = this->getY() - 1; i > dstY; i--)
		{
			if (i != dstY && board(this->getX(), i) != nullptr)
			{
				return no_invalid;
			}
		}
		for (int i = this->getX() + 1; i < dstX; i++)
		{
			if (board(i, this->getY()) != nullptr)
			{
				return no_invalid;
			}
		}
		for (int i = this->getX() - 1; i > dstX; i--)
		{
			if (board(i, this->getY()) != nullptr)
			{
				return no_invalid;
			}
		}
		if (board(dstX, dstY) != nullptr && board(dstX, dstY)->getColor() == board(this->getX(), this->getY())->getColor())
		{
			return no_invalid;
		}
	}
	else
	{
		return no_invalid;
	}

	return yes_valid;
}

std::vector<char>* Rook::isThreatening(Board& board) const
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


