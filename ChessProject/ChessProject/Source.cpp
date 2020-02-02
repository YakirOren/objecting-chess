/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "stdafx.h"
#include "ath.h"
#include "Board.h"
#include "chessUtills.h"


using std::cout;
using std::endl;
using std::string;


int main()
{
	//system("..\\..\\chessGraphics.exe");
	srand(time_t(NULL));

	Pipe* p = chessUtills::initBoard();
	if (p == nullptr)
	{
		system("pause");
		return 0;
	}

	Board board(BOARD_LAYOUT);
	int response = 1;
	string msgFromGraphics = p->getMessageFromGraphics();
	int* boardCords = nullptr;
	string retCode = "";

	//game loop
	while (response != 0)
	{
		boardCords = chessUtills::parseGuiResponse(msgFromGraphics);
		
		if (board(boardCords[0], boardCords[1]) != nullptr)
		{
			//TODO check all the codes
		}
		else
		{
			retCode = invalid_src_is_not_piece;
		}

		response = chessUtills::sendMsg(p, retCode);
		delete[] boardCords;
	}

	system("pause");
	return 0;
}