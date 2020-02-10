#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Queen :
	public Piece
{
public:
	Queen(const int& x, const int& y, const int& color);
	~Queen();

	int canMoveTo(Board& board, const int& dstX, const int& dstY);
	std::vector<char>* isThreatening(Board& board);
};

