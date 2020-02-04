#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Bishop :
	public Piece
{
public:
	Bishop(int x, int y, int color);
	~Bishop();

	int canMoveTo(Board& board, int dstX, int dstY) const;
	std::vector<char>* isThreatening(Board board) const;
	void draw() const;

};

