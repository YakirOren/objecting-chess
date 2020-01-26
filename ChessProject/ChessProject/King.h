#pragma once
#include "piece.h"
class King : public Piece
{

public:
	King(int x, int y, int color);
	~King();

	bool canMoveTo(Board chess, int dstX, int dstY) const;
	bool isCheck() const;
	bool isThreatening() const;
	void draw() const;
	

};

