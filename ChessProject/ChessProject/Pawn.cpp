#include "Pawn.h"

Pawn::Pawn(int x, int y, int color) : Piece(color, x, y, pawn)
{
}

Pawn::~Pawn()
{
}

int Pawn::canMoveTo(Board& board, int dstX, int dstY) const
{
	return yes_valid;
}

std::vector<char>* Pawn::isThreatening(Board board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

void Pawn::draw() const
{
}
