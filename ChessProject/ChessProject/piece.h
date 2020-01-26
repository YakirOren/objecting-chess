#pragma once
#include "ath.h"



class Piece
{
protected:
	int color; //0 white 1 black
	int x;
	int y;
	char symbol;

	
public:
	virtual bool canMoveTo(Board chess,int dstX, int dstY) const;
	virtual bool isCheck() const ;
	virtual bool isThreatening() const;
	virtual void draw() const;
	
	
	Piece& operator= (Piece& other);
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

