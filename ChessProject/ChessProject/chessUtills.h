#pragma once
#include "stdafx.h"
#include "Pipe.h"
#include "consts.h"

class chessUtills
{
public:
	static int check();
	static void parseGuiResponse(std::string guiString, int* cords);

	static void sendMsg(Pipe* p, std::string msgToGraphics);
	static bool getMsg(Pipe* p, std::string* msgToGraphics);
	static Pipe* initBoard();

	static void closePipe(Pipe* p);

};



