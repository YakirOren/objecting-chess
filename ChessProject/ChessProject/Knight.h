#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Knight :
	public Piece
{
public:
	Knight(const int& x, const int& y, const int& color);
	~Knight();

	int canMoveTo(Board& board, const int& dstX, const int& dstY);
	std::vector<char>* isThreatening(Board& board);


};

