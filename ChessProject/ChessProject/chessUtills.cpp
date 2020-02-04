#include "chessUtills.h"



bool chessUtills::isCheck(Board& board, Piece& pieceToCheck)
{
	bool check = false;
	std::vector<char>* threats = pieceToCheck.isThreatening(board); // getting a vector of all the pieces that are being threated by the piece   
	for (int i = 0; i < threats->size(); i++)//looping over all elements in the vector 
	{
		if (((*threats)[i] == 'k') || ((*threats)[i] == 'K')) // checking if anyone of them is a king
		{
			check = true; // we found that a piece somewhere on the board is threatening on a king in other words, getting check.
		}
	}
	delete[] threats; // freeing the memory (the vector was alloceted with new so it needs to be freed) 

	return check;
}

void chessUtills::parseGuiResponse(std::string guiString, int* cords)
{
	// [src x, src y, dst x, dst y]

	cords[0] = (guiString[0] - 'a');
	cords[1] = 7 - (guiString[1] - '1');
	cords[2] = (guiString[2] - 'a');
	cords[3] = 7 - (guiString[3] - '1');
}

void chessUtills::sendMsg(Pipe* p, std::string msgToGraphics)
{
	// send result to graphics		
	p->sendMessageToGraphics((char*)msgToGraphics.c_str());
}

// function will put response in the param msgFromGraphics and return true if connection ended
bool chessUtills::getMsg(Pipe* p, std::string* msgFromGraphics)
{
	// get message from graphics
	*msgFromGraphics = p->getMessageFromGraphics();

	return *msgFromGraphics == "quit" ? true : false;
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


