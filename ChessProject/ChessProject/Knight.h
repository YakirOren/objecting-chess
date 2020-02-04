#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Knight :
	public Piece
{
public:
	Knight(int x, int y, int color);

	bool canMoveTo(Board board, int dstX, int dstY);
	bool isCheck(Board board) const;
	std::vector<char>* isThreatening(Board board) const;


};

