#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Knight :
	public Piece
{
public:
	Knight(int x, int y, int color);
	~Knight();

	int canMoveTo(Board& board, int dstX, int dstY) const;
	std::vector<char>* isThreatening(Board& board) const;


};

