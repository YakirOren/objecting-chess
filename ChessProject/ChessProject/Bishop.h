#pragma once
#include "Board.h"
#include "consts.h"
#include "stdafx.h"

class Bishop :
	public Piece
{
public:
	Bishop(const int& x, const int& y, const int& color);
	~Bishop();

	int canMoveTo(Board& board, const int& dstX, const int& dstY) const;
	std::vector<char>* isThreatening(Board& board) const;

};

