#pragma once
#include "piece.h"
#include "consts.h"
#include "stdafx.h"

class Board;
class King :
	public Piece
{
public:
	King(const int& x, const int& y, const int& color);
	~King();

	int canMoveTo(Board& board, const int& dstX, const int& dstY) const;
	std::vector<char>* isThreatening(Board& board) const;
};

