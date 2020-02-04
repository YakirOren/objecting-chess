#pragma once
#include "consts.h"
#include "Piece.h"

class Queen :
	public Piece
{
public:
	Queen(int x, int y, int color);
	~Queen();

	bool canMoveTo(Piece*** board, int dstX, int dstY) const;
	bool isCheck(Piece*** board) const;
	std::vector<char>* isThreatening(Piece*** board) const;
	void draw() const;
};

