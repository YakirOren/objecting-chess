#pragma once
#include "consts.h"
#include "board.h"


class piece
{
protected:
	int color; //0 white 1 black
	int x;
	int y;
	char symbol;


public:
	virtual bool canMoveTo(Board chess,int dstX, int dstY) const = 0;
	virtual bool isCheck() const = 0;
	virtual bool isThreatening() const = 0;
	virtual void draw() const = 0;

	
	char getSymbol();
	int getColor();
	int getX();
	int getY();
	
	void setPos(int x, int y);

	piece(int color, int x, int y);
	~piece();
};

