#pragma once
class Board;
#include "Board.h"
#include "consts.h"
#include "stdafx.h"


class Piece
{
protected:
	int color; //0 white 1 black
	int x;
	int y;
	char symbol;


public:
	virtual int canMoveTo(Board& board, int dstX, int dstY) const;
	virtual std::vector<char>* isThreatening(Board& board) const;
	virtual void draw() const;


	Piece& operator= (Piece& other);
	char getSymbol() const;
	int getX() const;
	int getY() const;
	int getColor() const;

	void setSymbol(char symbol);
	void setColor(int color);
	void setPos(int x, int y);

	Piece(int color, int x, int y, char symbol);
	Piece();
	~Piece();
};

