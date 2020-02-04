#include "King.h"


King::King(int x, int y, int color) : Piece(color, x, y, king){

}


King::~King()
{
}

bool King::canMoveTo(Board board, int dstX, int dstY) const
{
	return false;
}

bool King::isCheck(Board board) const
{
	return false;
}

std::vector<char>* King::isThreatening(Board board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

void King::draw() const
{
}
