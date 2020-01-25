#pragma once
#include "piece.h"

class Rook :
	public piece
{
	Rook(int color, int x, int y);

	bool canMoveTo(Board chess, int dstX, int dstY);
	bool isCheck() const;
	bool isThreatening() const;

	~Rook();

};

