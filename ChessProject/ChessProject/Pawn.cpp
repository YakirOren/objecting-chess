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

bool Pawn::isCheck(Piece*** board) const
{
	return false;
}

std::vector<char>* Pawn::isThreatening(Piece*** board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

void Pawn::draw() const
{
}
