#include "Pawn.h"

Pawn::Pawn(int x, int y, int color) : Piece(color, x, y, pawn)
{
}

Pawn::~Pawn()
{
}

bool Pawn::canMoveTo(Piece*** board, int dstX, int dstY) const
{
	return false;
}

bool Pawn::isCheck() const
{
	return false;
}

bool Pawn::isThreatening() const
{
	return false;
}

void Pawn::draw() const
{
}
