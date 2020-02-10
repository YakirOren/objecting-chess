#include "Pawn.h"

Pawn::Pawn(const int& x, const int& y, const int& color) : Piece(color, x, y, pawn)
{

	this->moveTwo = true;
}

Pawn::~Pawn()
{
}


int Pawn::canMoveTo(Board& board, const int& dstX, const int& dstY)
{

	if (board(dstX, dstY) == nullptr)
	{
		if (dstY == this->getY())
		{
			if ((dstX == this->getX() - 2) && moveTwo && this->getColor() == colors::white)
			{
				this->moveTwo = false;
				return yes_valid;
			}
			else if (dstX == this->getX() - 1 && this->getColor() == colors::white)
			{
				this->moveTwo = false;
				return yes_valid;
			}
			if ((dstX == this->getX() + 2) && moveTwo && this->getColor() == colors::black)
			{
				this->moveTwo = false;
				return yes_valid;
			}
			else if (dstX == this->getX() + 1 && this->getColor() == colors::black)
			{
				this->moveTwo = false;
				return yes_valid;
			}
			else
			{
				return no_invalid;
			}
		}
		else
		{
			return no_invalid;
		}

	}
	else
	{
		if (dstY == this->getY() - 1 || dstY == this->getY() + 1)
		{
			if (this->getColor() == colors::black && dstX == this->getX() + 1)
			{
				return yes_valid;
			}
			else if (this->getColor() == colors::white && dstX == this->getX() - 1)
			{
				return yes_valid;
			}
			else
			{
				return no_invalid;
			}

		}
		else
		{
			return no_invalid;
		}

	}
}

std::vector<char>* Pawn::isThreatening(Board& board)
{
	std::vector<char>* threats = new std::vector<char>;


	if (this->getColor() == colors::black)
	{
		if (board(this->getX() + 1, this->getY() - 1) != nullptr)
		{
			threats->push_back(board(this->getX() + 1, this->getY() - 1)->getSymbol());
		}

		if (board(this->getX() + 1, this->getY() + 1) != nullptr)
		{
			threats->push_back(board(this->getX() + 1, this->getY() - 1)->getSymbol());
		}

	}

	if (this->getColor() == colors::white)
	{
		if (board(this->getX() - 1, this->getY() - 1) != nullptr)
		{
			threats->push_back(board(this->getX() - 1, this->getY() - 1)->getSymbol());
		}

		if (board(this->getX() - 1, this->getY() + 1) != nullptr)
		{
			threats->push_back(board(this->getX() - 1, this->getY() - 1)->getSymbol());
		}

	}

	return threats;
}