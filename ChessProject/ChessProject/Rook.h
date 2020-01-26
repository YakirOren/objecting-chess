#pragma once
#include "ath.h"

class Rook :
	public Piece
{
public:
	Rook(int x, int y, int color);

	bool canMoveTo(Board chess, int dstX, int dstY);
	bool isCheck() const;
	bool isThreatening() const;
	

	~Rook();

};

