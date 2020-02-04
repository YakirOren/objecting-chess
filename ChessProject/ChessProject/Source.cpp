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

		// check if theres a piece on the src point and its the current player color
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
					}
					else
					{
						retCode = invalid_dst_is_src;
					}

				}
				else
				{
					retCode = invalid_index;
				}
			}
			else
			{
				retCode = invalid_dst_is_current_player;
			}
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