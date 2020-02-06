#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Pawn :
	public Piece
{
public:
	Pawn(const int& x, const int& y, const int& color);
	~Pawn();

	int canMoveTo(Board& board, const int& dstX, const int& dstY) const;
	std::vector<char>* isThreatening(Board& board) const;
};

