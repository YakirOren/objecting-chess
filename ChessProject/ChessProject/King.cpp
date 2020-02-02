#include "King.h"


King::King(int x, int y, int color) : Piece(color, x, y, king){

}


King::~King()
{
}

bool King::canMoveTo(Piece*** board, int dstX, int dstY) const
{
	return false;
}

bool King::isCheck() const
{
	return false;
}

std::vector<char>* King::isThreatening() const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

void King::draw() const
{
}
