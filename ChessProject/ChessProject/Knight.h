#pragma once
#include "ath.h"

class Knight :
	public Piece
{
public:
	Knight(int x, int y, int color);

	bool canMoveTo(Board chess, int dstX, int dstY);
	bool isCheck() const;
	bool isThreatening() const;


};

