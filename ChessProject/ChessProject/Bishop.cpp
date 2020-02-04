#include "Bishop.h"

Bishop::Bishop(int x, int y, int color) : Piece(color, x , y, bishop)
{
}

Bishop::~Bishop()
{
}

bool Bishop::canMoveTo(Board board, int dstX, int dstY) const
{
	return false;
}

bool Bishop::isCheck(Board board) const
{
	return false;
}

std::vector<char>* Bishop::isThreatening(Board board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

void Bishop::draw() const
{
}
