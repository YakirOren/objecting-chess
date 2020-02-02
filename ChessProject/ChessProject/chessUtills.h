#pragma once
#include "stdafx.h"
#include "Pipe.h"
#include "consts.h"

class chessUtills
{
public:
	static int check();
	static int* parseGuiResponse(std::string guiString);

	static int sendMsg(Pipe* p, std::string msgToGraphics);
	static Pipe* initBoard();

	static void closePipe(Pipe* p);

};



