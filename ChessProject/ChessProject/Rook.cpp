#include "Rook.h"

Rook::Rook(int color, int x, int y) : piece(color, x, y)
{
	
}

bool Rook::canMoveTo(Board chess, int dstX, int dstY)
{


	return false;
}

bool Rook::isCheck() const
{
	return false;
}

bool Rook::isThreatening() const
{
	return false;
}

Rook::~Rook()
{

}


