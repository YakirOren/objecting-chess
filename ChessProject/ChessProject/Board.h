#pragma once
#include "consts.h"
#include "stdafx.h"
#include "Piece.h"

class Board
{
private:
	Piece** board;
	int playerTurn;

public:
	Board(std::string startingBoard);
	~Board();

	// misc
	void draw();

	// getters
	int getPlayerTurn();
	Piece getSlot(int dstX, int dstY);

	// setters
	bool updateBoard(int srcX, int srcY, int dstX, int dstY);
};

