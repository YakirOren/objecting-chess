#pragma once
#include "consts.h"
#include "Piece.h"

class Rook :
	public Piece
{
public:
	Rook(int x, int y, int color);

	bool canMoveTo(Piece*** board, int dstX, int dstY);
	bool isCheck() const;
	bool isThreatening() const;
	

	~Rook();

};

