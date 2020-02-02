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
	//game loop
	int response = 1;
	string msgFromGraphics = p->getMessageFromGraphics();
	int* a = {0};
	string retCode;

	while (response != 0)
	{
		a = chessUtills::parseGuiResponse(msgFromGraphics);
		
		//logics

		response = chessUtills::sendMsg(p, retCode);

	}


}