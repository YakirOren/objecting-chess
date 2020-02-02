#pragma once
#include "consts.h"
#include "Piece.h"
#include "stdafx.h"

class Rook :
	public Piece
{
public:
	Rook(int x, int y, int color);

	bool canMoveTo(Piece*** board, int dstX, int dstY);
	bool isCheck() const;
	std::vector<char>* isThreatening() const;
	

	~Rook();

};

