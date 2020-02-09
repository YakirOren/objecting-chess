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
	Board(const std::string& startingBoard);
	~Board();

	// misc
	void draw() const;
	
	// getters
	int getPlayerTurn() const;
	Piece* operator()(const int& dstX, const int& dstY) const;

	// setters
	void nextTurn();
	bool updateBoard(const int& srcX, const int& srcY, const int& dstX, const int& dstY);
	void setPiece(Piece* piece, const int& dstX, const int& dstY);
};
