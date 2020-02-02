#pragma once
#include "ath.h"
#include "stdafx.h"

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
	Piece getSlot(int dstX, int dstY) const;

	// setters
	bool updateBoard(int srcX, int srcY, int dstX, int dstY);
};
