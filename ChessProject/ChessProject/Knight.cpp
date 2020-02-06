#include "Knight.h"

Knight::Knight(const int& x, const int& y, const int& color) : Piece(color, x, y, knight)
{
}

Knight::~Knight()
{
}

int Knight::canMoveTo(Board& board, const int& dstX, const int& dstY) const
{
	if ((abs(dstY - this->getY()) == 2 && abs(dstX - this->getX()) == 1 ||
		abs(dstX - this->getX()) == 2 && abs(dstY - this->getY()) == 1) && (board(dstX, dstY) == nullptr || board(dstX, dstY)->getColor() != this->getColor()))
	{
		return yes_valid;
	}
	return no_invalid;
}

std::vector<char>* Knight::isThreatening(Board& board) const
{
	std::vector<char>* threats = new std::vector<char>;
	for (int x = this->getX() - 2; x <= this->getX() + 2; x++)
	{
		for (int y = this->getY() - 2; y <= this->getY() + 2; y++)
		{
			if (x >= 0 && x <= 7 && y >= 0 && y <= 7 && canMoveTo(board, x, y))
			{
				threats->push_back(board(x, y)->getSymbol());
			}
		}
	}
	return threats;
}


