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

	int canMoveTo(Board& board, const int& dstX, const int& dstY) const;
	std::vector<char>* isThreatening(const Board& board) const;


};

