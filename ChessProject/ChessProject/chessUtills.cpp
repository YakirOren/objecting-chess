#include "chessUtills.h"



bool chessUtills::isCheck(const Board& board, Piece& pieceToCheck)
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

// check the cords from the gui and return some codes
char chessUtills::isValidCords(const Board& board, const int& srcX, const int& srcY, const int& dstX, const int& dstY)
{
	// check if the cords are outside the board
	if (srcX >= 0 && srcX <= BOARD_SIZE ||
		srcY >= 0 && srcY <= BOARD_SIZE ||
		dstX >= 0 && dstX <= BOARD_SIZE ||
		dstY >= 0 && dstY <= BOARD_SIZE)
	{
		// check if theres a piece on the src point and its the current player color
		if (board(srcX, srcY) != nullptr &&
			board(srcX, srcY)->getColor() == board.getPlayerTurn())
		{
			// check if the dst is the same color as the current player
			if (board(dstX, dstY) == nullptr ||
				board.getPlayerTurn() != board(dstX, dstY)->getColor())
			{
				// check is src equals to the dst
				if (srcX != dstX || srcY != dstY)
				{
					return valid;

				}
				return invalid_dst_is_src;
			}
			return invalid_dst_is_current_player;
		}
		return invalid_src_is_not_piece;
	}
	return invalid_index;
}

void chessUtills::parseGuiResponse(const std::string& guiString, int* cords)
{
	// [src x, src y, dst x, dst y]

	cords[0] = 7 - (guiString[1] - '1');
	cords[1] = (guiString[0] - 'a');
	cords[2] = 7 - (guiString[3] - '1');
	cords[3] = (guiString[2] - 'a');
}

void chessUtills::sendMsg(Pipe* p, const std::string& msgToGraphics)
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

/*
	this function is checking if the pieces in the given color
	are threatening on the other color in other words, the player has check on the other player
*/
bool chessUtills::isThereCheckForColor(const int& color, const Board& board)
{
	bool check = false;
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)//looping over all the pieces in the board 
		{
			if (board(x,y) != nullptr) // checking that the slot we are working on is not empty
			{
				if (board(x, y)->getColor() == color) // getting only the pieces with the color we want
				{
					std::vector<char>* threats = board(x, y)->isThreatening(board); // getting a vector of all the pieces that are being threated by the piece   
					for (int i = 0; i < threats->size(); i++)//looping over all elements in the vector 
					{
						if (((*threats)[i] == 'k') || ((*threats)[i] == 'K')) // checking if anyone of them is a king
						{
							check = true; // we found that a piece somewhere on the board is threatening on a king in other words, getting check.
						}
					}
					delete[] threats; // freeing the memory (the vector was alloceted with new so it needs to be freed) 
				}

			}
		}
	}

	return check;
}


