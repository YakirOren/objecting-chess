#pragma once
#include "stdafx.h"
#include "Pipe.h"
#include "consts.h"
#include "piece.h"

class chessUtills
{
public:
	static bool isCheck(Board& board, Piece& pieceToCheck);

	static char isValidCords(Board& board, int srcX, int srcY, int dstX, int dstY);

	static void parseGuiResponse(std::string guiString, int* cords);

	static void sendMsg(Pipe* p, std::string msgToGraphics);
	static bool getMsg(Pipe* p, std::string* msgToGraphics);
	static Pipe* initBoard();

	static bool isThereCheckForColor(int color, Board& board);
	static void closePipe(Pipe* p);

};



