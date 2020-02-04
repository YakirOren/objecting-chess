#pragma once
#include "consts.h"
#include "Piece.h"

class Bishop :
	public Piece
{
public:
	Bishop(int x, int y, int color);
	~Bishop();

	bool canMoveTo(Piece*** board, int dstX, int dstY) const;
	bool isCheck(Piece*** board) const;
	std::vector<char>* isThreatening(Piece*** board) const;
	void draw() const;

};

