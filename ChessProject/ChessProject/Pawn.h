#pragma once
#include "consts.h"
#include "piece.h"

class Pawn :
	public Piece
{
public:
	Pawn(int x, int y, int color);
	~Pawn();

	bool canMoveTo(Piece*** board, int dstX, int dstY) const;
	bool isCheck() const;
	bool isThreatening() const;
	void draw() const;
};

