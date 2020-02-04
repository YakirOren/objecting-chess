#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Knight :
	public Piece
{
public:
	Knight(int x, int y, int color);

	int canMoveTo(Board& board, int dstX, int dstY);
	std::vector<char>* isThreatening(Board board) const;


};

