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
	virtual int canMoveTo(Board& board, const int& dstX, const int& dstY) = 0;
	virtual std::vector<char>* isThreatening(Board& board) = 0;


	Piece& operator= (Piece& other);
	char getSymbol() const;
	int getX() const;
	int getY() const;
	int getColor() const;

	void setSymbol(const char symbol);
	void setColor(const int color);
	void setPos(const int x, const int y);

	Piece(const int color, const int x, const int y, const char symbol);
	Piece();
	~Piece();
};

