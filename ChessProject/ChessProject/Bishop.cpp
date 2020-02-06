#include "Bishop.h"

Bishop::Bishop(int x, int y, int color) : Piece(color, x , y, bishop)
{
}

Bishop::~Bishop()
{
}

int Bishop::canMoveTo(Board& board, int dstX, int dstY) const
{
	return yes_valid;
}

std::vector<char>* Bishop::isThreatening(const Board& board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}
