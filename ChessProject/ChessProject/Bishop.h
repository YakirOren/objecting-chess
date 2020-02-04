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

	bool canMoveTo(Board board, int dstX, int dstY) const;
	bool isCheck(Board board) const;
	std::vector<char>* isThreatening(Board board) const;
	void draw() const;

};

