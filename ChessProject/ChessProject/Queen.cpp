#include "Queen.h"

Queen::Queen(int x, int y, int color) : Piece(color, x, y, queen)
{
}

Queen::~Queen()
{
}

int Queen::canMoveTo(Board board, int dstX, int dstY) const
{
	return yes_valid;
}

std::vector<char>* Queen::isThreatening(Board board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

void Queen::draw() const
{
}
