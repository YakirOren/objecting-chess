#pragma once
#include "piece.h"
#include "consts.h"
#include "stdafx.h"

class Board;
class King : 
	public Piece
{
public:
	King(int x, int y, int color);
	~King();

	bool canMoveTo(Board board, int dstX, int dstY) const;
	bool isCheck(Board board) const;
	std::vector<char>* isThreatening(Board board) const;
	void draw() const;
	

};

