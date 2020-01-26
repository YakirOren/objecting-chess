#pragma once
#include "piece.h"
class Knight :
	public Piece
{
	Knight(int x, int y, int color);

	bool canMoveTo(Board chess, int dstX, int dstY);
	bool isCheck() const;
	bool isThreatening() const;


};

