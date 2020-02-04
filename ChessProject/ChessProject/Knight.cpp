#include "Knight.h"

Knight::Knight(int x, int y, int color) : Piece(color, x, y, knight)
{
}

bool Knight::canMoveTo(Piece*** board, int dstX, int dstY)
{
	return false;
}

bool Knight::isCheck(Piece*** board) const
{
	return false;
}

std::vector<char>* Knight::isThreatening(Piece*** board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

