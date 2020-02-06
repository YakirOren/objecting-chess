#pragma once
#include "stdafx.h"
#include "Pipe.h"
#include "consts.h"
#include "piece.h"

class chessUtills
{
public:
	static bool isCheck(const Board& board, Piece& pieceToCheck);

	static char isValidCords(const Board& board, const int& srcX, const int& srcY, const int& dstX, const int& dstY);

	static void parseGuiResponse(const std::string& guiString, int* cords);

	static void sendMsg(Pipe* p, const std::string& msgToGraphics);
	static bool getMsg(Pipe* p, std::string* msgToGraphics);
	static Pipe* initBoard();

	static bool isThereCheckForColor(const int& color, const Board& board);
	static void closePipe(Pipe* p);

};



