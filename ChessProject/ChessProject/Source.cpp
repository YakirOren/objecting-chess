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
	bool exit = false;
	string msgFromGraphics = p->getMessageFromGraphics();
	int* boardCords = new int[4];
	string retCode = "1";

	//game loop
	while (exit != true)
	{
		chessUtills::parseGuiResponse(msgFromGraphics, boardCords);

		// check if theres a piece on the src point and its the current player color
		cout << boardCords[0];
		cout << boardCords[1];
		cout << boardCords[2];
		cout << boardCords[3];
		cout << endl;
		if (board(boardCords[0], boardCords[1]) != nullptr &&
			board(boardCords[0], boardCords[1])->getColor() == board.getPlayerTurn())
		{
			// check if the dst is the same color as the current player
			if (board.getPlayerTurn() == board(boardCords[2], boardCords[3])->getColor())
			{
				// check if indexes are outside the board
				if (boardCords[0] >= 0 && boardCords[0] <= BOARD_SIZE || 
					boardCords[1] >= 0 && boardCords[1] <= BOARD_SIZE || 
					boardCords[2] >= 0 && boardCords[2] <= BOARD_SIZE || 
					boardCords[3] >= 0 && boardCords[3] <= BOARD_SIZE)
				{
					if (boardCords[0] == boardCords[2] && boardCords[1] == boardCords[3])
					{
						/*
						TODO check all the codes
						valid = 0,
						valid_check = 1,
						invalid_will_check_current_player = 4,
						invalid_piece_move = 6,
						valid_checkmate = 8,

						TODO put "board.nextTurn();" after return 0 or 1
						*/
						retCode[0] = valid;
					}
					else
					{
						retCode[0] = invalid_dst_is_src;
					}

				}
				else
				{
					retCode[0] = invalid_index;
				}
			}
			else
			{
				retCode[0] = invalid_dst_is_current_player;
			}
		}
		else
		{
			retCode[0] = invalid_src_is_not_piece;
		}

		chessUtills::sendMsg(p, retCode);
		exit = chessUtills::getMsg(p, &msgFromGraphics);
	}

	delete[] boardCords;
	system("pause");
	return 0;
}