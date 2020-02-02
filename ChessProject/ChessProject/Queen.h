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
	bool isCheck() const;
	std::vector<char>* isThreatening() const;
	void draw() const;
};

