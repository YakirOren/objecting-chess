#include "Knight.h"

Knight::Knight(int x, int y, int color) : Piece(color, x, y, knight)
{
}

bool Knight::canMoveTo(Board chess, int dstX, int dstY)
{
	return false;
}

bool Knight::isCheck() const
{
	return false;
}

bool Knight::isThreatening() const
{
	return false;
}

