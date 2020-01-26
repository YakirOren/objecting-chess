#include "King.h"


King::King(int x, int y, int color) : Piece(color, x, y, king){

}


King::~King()
{
}

bool King::canMoveTo(Board chess, int dstX, int dstY) const
{
	return false;
}

bool King::isCheck() const
{
	return false;
}

bool King::isThreatening() const
{
	return false;
}

void King::draw() const
{
}
