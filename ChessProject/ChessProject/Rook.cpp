#include "Rook.h"

Rook::Rook(int x, int y, int color) : Piece(color, x, y, rook)
{
	
}

bool Rook::canMoveTo(Piece*** board, int dstX, int dstY)
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


