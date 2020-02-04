#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Queen :
	public Piece
{
public:
	Queen(int x, int y, int color);
	~Queen();

	int canMoveTo(Board board, int dstX, int dstY) const;
	std::vector<char>* isThreatening(Board board) const;
	void draw() const;
};

