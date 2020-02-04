#pragma once
#include "piece.h"
#include "stdafx.h"

class King;
class Piece;
class Board
{
private:
	Piece*** board;
	int playerTurn;

public:
	Board(std::string startingBoard);
	~Board();

	// misc
	void draw() const;

	// getters
	int getPlayerTurn() const;
	Piece* operator()(int dstX, int dstY) const;

	// setters
	void nextTurn();
	bool updateBoard(int srcX, int srcY, int dstX, int dstY);
};
