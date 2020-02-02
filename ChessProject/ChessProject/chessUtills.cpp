#include "chessUtills.h"

int* chessUtills::parseGuiResponse(std::string guiString)
{
	int* response = new int[4];
	// [src x, srcy, dst x, dst y]

	response[0] = guiString[0] - 'a';
	response[1] = guiString[1] - '1';
	response[2] = guiString[2] - 'a';
	response[3] = guiString[1] - '1';

	return response;
}

int chessUtills::sendMsg(Pipe* p, std::string msgToGraphics)
{
	// YOUR CODE
	//strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

	///******* JUST FOR EREZ DEBUGGING ******/
	//int r = rand() % 10; // just for debugging......
	//msgToGraphics[0] = (char)(1 + '0');
	//msgToGraphics[1] = 0;
	///******* JUST FOR EREZ DEBUGGING ******/


	// return result to graphics		
	p->sendMessageToGraphics((char*)msgToGraphics.c_str());

	// get message from graphics
	string msgFromGraphics = p->getMessageFromGraphics();

	std::cout << msgFromGraphics << std::endl;
	

	return msgFromGraphics != "quit" ? 1 : 0;
}

Pipe* chessUtills::initBoard()
{

	Pipe* p = new Pipe;
	bool isConnect = p->connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p->connect();
		}
		else
		{
			closePipe(p);
		
			return nullptr;
		}
	}

	p->sendMessageToGraphics((char*)BOARD_LAYOUT);   // send the board string

	return p;
}

void chessUtills::closePipe(Pipe* p)
{
	p->close();
	delete[] p;
}


