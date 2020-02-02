#include "Knight.h"

Knight::Knight(int x, int y, int color) : Piece(color, x, y, knight)
{
}

bool Knight::canMoveTo(Piece*** board, int dstX, int dstY)
{
	return false;
}

bool Knight::isCheck() const
{
	return false;
}

std::vector<char>* Knight::isThreatening() const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

