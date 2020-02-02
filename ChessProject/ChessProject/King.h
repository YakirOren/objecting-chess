#pragma once
#include "consts.h"
#include "Piece.h"

class King : 
	public Piece
{
public:
	King(int x, int y, int color);
	~King();

	bool canMoveTo(Piece*** board, int dstX, int dstY) const;
	bool isCheck() const;
	bool isThreatening() const;
	void draw() const;
	

};

