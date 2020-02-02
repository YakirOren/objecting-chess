#include "Bishop.h"

Bishop::Bishop(int x, int y, int color) : Piece(color, x , y, bishop)
{
}

Bishop::~Bishop()
{
}

bool Bishop::canMoveTo(Piece*** board, int dstX, int dstY) const
{
	return false;
}

bool Bishop::isCheck() const
{
	return false;
}

std::vector<char>* Bishop::isThreatening() const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

void Bishop::draw() const
{
}
