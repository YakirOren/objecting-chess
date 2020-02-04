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
	int isMovable = 0;
	string msgFromGraphics = p->getMessageFromGraphics();
	int* boardCords = new int[4]; // [src x, src y, dst x, dst y]
	string retCode = "1";

	//game loop
	while (exit != true)
	{
		chessUtills::parseGuiResponse(msgFromGraphics, boardCords);
		for (int i = 0; i < 4; i++)
		{
			cout << boardCords[i];
		}
		cout << endl;
		// check if indexes are outside the board
		if (boardCords[0] >= 0 && boardCords[0] <= BOARD_SIZE ||
			boardCords[1] >= 0 && boardCords[1] <= BOARD_SIZE ||
			boardCords[2] >= 0 && boardCords[2] <= BOARD_SIZE ||
			boardCords[3] >= 0 && boardCords[3] <= BOARD_SIZE)
		{
			// check if theres a piece on the src point and its the current player color
			if (board(boardCords[1], boardCords[0]) != nullptr &&
				board(boardCords[1], boardCords[0])->getColor() == board.getPlayerTurn())
			{
				// check if the dst is the same color as the current player
				if (board(boardCords[3], boardCords[2]) == nullptr ||
					board.getPlayerTurn() != board(boardCords[3], boardCords[2])->getColor())
				{
					// check is src equals to the dst
					if (boardCords[0] != boardCords[2] || boardCords[1] != boardCords[3])
					{
						/*
						TODO check all the codes
						valid_check = 1,
						valid_checkmate = 8,

						TODO put "board.nextTurn();" after return 0 or 1
						*/
						isMovable = board(boardCords[1], boardCords[0])->canMoveTo(board, boardCords[3], boardCords[2]);
						if (isMovable == yes_valid)
						{
							retCode[0] = valid;
							board.updateBoard(boardCords[1], boardCords[0], boardCords[3], boardCords[2]);
							board.nextTurn();
						}
						else if (isMovable == no_invalid)
						{
							retCode[0] = invalid_piece_move;
						}
						else if (isMovable == no_invalid_will_chess_you)
						{
							retCode[0] = invalid_will_check_current_player;
						}
						else
						{
							retCode[0] = unknown_error;
						}
					}
					else
					{
						retCode[0] = invalid_dst_is_src;
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
		}
		else
		{
			retCode[0] = invalid_index;
		}

		chessUtills::sendMsg(p, retCode);
		board.draw();
		exit = chessUtills::getMsg(p, &msgFromGraphics);
	}

	delete[] boardCords;
	system("pause");
	return 0;
}