#pragma once
#include "consts.h"
#include "board.h"



class Piece
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
	int getX(); 
	int getY(); 
	int getColor();
	
	void setSymbol(char symbol);
	void setColor(int color);
	void setPos(int x, int y);

	Piece(int color, int x, int y,char symbol);
	Piece();
	~Piece();
};

