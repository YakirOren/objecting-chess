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
	bool isCheck(Piece*** board) const;
	std::vector<char>* isThreatening(Piece*** board) const;
	void draw() const;
	

};

