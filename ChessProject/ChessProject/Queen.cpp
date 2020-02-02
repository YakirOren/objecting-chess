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

bool Queen::isThreatening() const
{
	return false;
}

void Queen::draw() const
{
}
