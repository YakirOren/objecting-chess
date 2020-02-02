#include "Queen.h"

Queen::Queen(int x, int y, int color) : Piece(color, x, y, queen)
{
}

Queen::~Queen()
{
}

bool Queen::canMoveTo(Piece*** board, int dstX, int dstY) const
{
	return false;
}

bool Queen::isCheck() const
{
	return false;
}

std::vector<char>* Queen::isThreatening() const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

void Queen::draw() const
{
}
