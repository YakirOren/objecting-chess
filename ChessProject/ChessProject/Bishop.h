#pragma once
#include "piece.h"

class Bishop :
	public Piece
{

	Bishop(int x, int y, int color);
	~Bishop();

	bool canMoveTo(Board chess, int dstX, int dstY) const;
	bool isCheck() const;
	bool isThreatening() const;
	void draw() const;

};

