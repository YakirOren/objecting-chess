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
	int plus_x = this->getX() + 1;
	int plus_y = this->getY() + 1;
	int minus_x = this->getX() - 1;
	int minus_y = this->getY() - 1;

	if (board(dstX, dstY) == nullptr)
	{
		if (dstY == this->getY())
		{
			if ((dstX == this->getX() - 2) && moveTwo && this->getColor() == colors::white)
			{
				this->moveTwo = false;
				return yes_valid;
			}
			else if (dstX == minus_x && this->getColor() == colors::white)
			{
				this->moveTwo = false;
				return yes_valid;
			}
			if ((dstX == this->getX() + 2) && moveTwo && this->getColor() == colors::black)
			{
				this->moveTwo = false;
				return yes_valid;
			}
			else if (dstX == plus_x && this->getColor() == colors::black)
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
		if (dstY == minus_y || dstY == plus_y)
		{
			if (this->getColor() == colors::black && dstX == plus_x)
			{
				return yes_valid;
			}
			else if (this->getColor() == colors::white && dstX == minus_x)
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

	int plus_x = this->getX() + 1;
	int plus_y = this->getY() + 1;
	int minus_x = this->getX() - 1;
	int minus_y = this->getY() - 1; 

	if (this->getColor() == colors::black)
	{

		if (plus_x >= 0 && plus_x < BOARD_SIZE)
		{
			if (minus_y >= 0 && minus_y < BOARD_SIZE && board(plus_x, minus_y) != nullptr && board(plus_x, minus_y)->getColor() != colors::black)
			{
				threats->push_back(board(plus_x, minus_y)->getSymbol());
			}

			if (plus_y >= 0 && plus_y < BOARD_SIZE && board(plus_x, plus_y) != nullptr && board(plus_x, plus_y)->getColor() != colors::black)
			{
				threats->push_back(board(plus_x, plus_y)->getSymbol());
			}
		}

	}

	if (this->getColor() == colors::white)
	{

		if (minus_x >= 0 && minus_x < BOARD_SIZE)
		{

			if (minus_y >= 0 && minus_y < BOARD_SIZE && board(minus_x, minus_y) != nullptr && board(minus_x, minus_y)->getColor() != colors::white)
			{
				threats->push_back(board(minus_x, minus_y)->getSymbol());
			}

			if (plus_y >= 0 && plus_y < BOARD_SIZE && board(minus_x, plus_y) != nullptr && board(minus_x, plus_y)->getColor() != colors::white)
			{
				threats->push_back(board(minus_x, plus_y)->getSymbol());
			}
		}

	}

	return threats;
}