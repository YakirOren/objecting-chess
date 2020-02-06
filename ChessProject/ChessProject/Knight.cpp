#include "Knight.h"

Knight::Knight(const int& x, const int& y, const int& color) : Piece(color, x, y, knight)
{
}

Knight::~Knight()
{
}

int Knight::canMoveTo(Board& board, const int& dstX, const int& dstY) const
{
	return yes_valid;
}

std::vector<char>* Knight::isThreatening(const Board& board) const
{
	return nullptr;
}


