#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Rook :
	public Piece
{
public:
	Rook(const int& x, const int& y, const int& color);

	int canMoveTo(Board& board, const int& dstX, const int& dstY) const;
	std::vector<char>* isThreatening(const Board& board) const;
	

	~Rook();

};

