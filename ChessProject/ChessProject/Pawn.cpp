#include "Pawn.h"

Pawn::Pawn(const int& x, const int& y, const int& color) : Piece(color, x, y, pawn)
{
}

Pawn::~Pawn()
{
}

int Pawn::canMoveTo(Board& board, const int& dstX, const int& dstY) const
{
	return yes_valid;
}

std::vector<char>* Pawn::isThreatening(const Board& board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}