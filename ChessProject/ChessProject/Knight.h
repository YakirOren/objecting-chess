#pragma once
#include "consts.h"
#include "Piece.h"

class Knight :
	public Piece
{
public:
	Knight(int x, int y, int color);

	bool canMoveTo(Piece*** board, int dstX, int dstY);
	bool isCheck() const;
	bool isThreatening() const;


};

