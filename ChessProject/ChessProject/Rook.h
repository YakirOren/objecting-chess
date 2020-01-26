#pragma once
#include "Piece.h"

class Rook :
	public Piece
{
	Rook(int color, int x, int y);

	bool canMoveTo(Board chess, int dstX, int dstY);
	bool isCheck() const;
	bool isThreatening() const;
	

	~Rook();

};

