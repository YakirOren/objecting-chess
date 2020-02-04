#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Rook :
	public Piece
{
public:
	Rook(int x, int y, int color);

	bool canMoveTo(Board board, int dstX, int dstY);
	bool isCheck(Board board) const;
	std::vector<char>* isThreatening(Board board) const;
	

	~Rook();

};

