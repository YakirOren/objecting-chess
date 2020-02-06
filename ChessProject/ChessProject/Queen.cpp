#include "Queen.h"

Queen::Queen(const int& x, const int& y, const int& color) : Piece(color, x, y, queen)
{
}

Queen::~Queen()
{
}

int Queen::canMoveTo(Board& board, const int& dstX, const int& dstY) const
{
	return yes_valid;
}

std::vector<char>* Queen::isThreatening(const Board& board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}
