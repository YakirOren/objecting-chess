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
	srand(time_t(NULL));

	Pipe* pip = chessUtills::initBoard();
	//game loop
	int response = 1;

	while (response != 0)
	{
		response = chessUtills::sendMsg(pip, "e4b4");

	}


}