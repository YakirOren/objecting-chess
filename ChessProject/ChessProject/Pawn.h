#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Pawn :
	public Piece
{
public:
	Pawn(int x, int y, int color);
	~Pawn();

	bool canMoveTo(Board board, int dstX, int dstY) const;
	bool isCheck(Board board) const;
	std::vector<char>* isThreatening(Board board) const;
	void draw() const;
};

