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
	bool isCheck() const;
	std::vector<char>* isThreatening() const;
	void draw() const;

};

