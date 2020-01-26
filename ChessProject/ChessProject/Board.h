#pragma once
#include "ath.h"
#include "stdafx.h"

class Board
{
private:
	Piece board[BOARD_SIZE][BOARD_SIZE];
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

