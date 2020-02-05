#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Pawn :
	public Piece
{
public:
	Pawn(int x, int y, int color);
	~Pawn();

	int canMoveTo(Board& board, int dstX, int dstY) const;
	std::vector<char>* isThreatening(Board& board) const;
};

