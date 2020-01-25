#pragma once
#include "const.h"

class piece
{
protected:
	int color; //0 white 1 black
	int x;
	int y;

public:
	virtual bool canMoveTo(Board chess,int dstX, int dstY) const = 0;
	virtual bool isCheck() const = 0;
	virtual bool isThreatening() const = 0;

	int getColor();
	int getX();
	int getY();

	void setPos(int x, int y);

	piece(int color, int x, int y);
	~piece();
};

