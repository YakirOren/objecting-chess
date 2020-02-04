#include "Knight.h"

Knight::Knight(int x, int y, int color) : Piece(color, x, y, knight)
{
}

bool Knight::canMoveTo(Board board, int dstX, int dstY)
{
	return false;
}

bool Knight::isCheck(Board board) const
{
	return false;
}

std::vector<char>* Knight::isThreatening(Board board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

