#include "Bishop.h"

Bishop::Bishop(const int& x, const int& y, const int& color) : Piece(color, x , y, bishop)
{
}

Bishop::~Bishop()
{
}

int Bishop::canMoveTo(Board& board, const int& dstX, const int& dstY) const
{
	return yes_valid;
}

std::vector<char>* Bishop::isThreatening(Board& board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}
