#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Pawn :
	public Piece

{
protected:
	bool moveTwo;

public:
	Pawn(const int& x, const int& y, const int& color);
	~Pawn();

	int canMoveTo(Board& board, const int& dstX, const int& dstY);
	std::vector<char>* isThreatening(Board& board);
};

