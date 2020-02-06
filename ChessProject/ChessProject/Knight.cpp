#include "Knight.h"

Knight::Knight(int x, int y, int color) : Piece(color, x, y, knight)
{
}

Knight::~Knight()
{
}

int Knight::canMoveTo(Board& board, int dstX, int dstY) const
{
	return yes_valid;
}

std::vector<char>* Knight::isThreatening(const Board& board) const
{
	return nullptr;
}


