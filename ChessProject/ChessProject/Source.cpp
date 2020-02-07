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
	if (p == nullptr) {
		system("pause");
		return 0;
	}

	Board board(BOARD_LAYOUT);
	bool exit = false;
	char currentChar = 'a';
	int isMovable = 0;
	string msgFromGraphics = p->getMessageFromGraphics();
	int* boardCords = new int[4]; // [src x, src y, dst x, dst y]
	string retCode = "1";

	//game loop
	while (exit != true)
	{
		chessUtills::parseGuiResponse(msgFromGraphics, boardCords);
		for (int i = 0; i < 4; i++) {
			cout << boardCords[i];
		}
		cout << endl;

		if ((retCode[0] = chessUtills::isValidCords(board, boardCords[0], boardCords[1], boardCords[2], boardCords[3])) == valid)
		{
			/*
			TODO check all the codes
			valid_check = 1,
			valid_checkmate = 8,

			TODO put "board.nextTurn();" after return 0 or 1
			*/
			isMovable = board(boardCords[0], boardCords[1])->canMoveTo(board, boardCords[2], boardCords[3]);


			if (isMovable == yes_valid) {
				retCode[0] = valid;
				board.updateBoard(boardCords[0], boardCords[1], boardCords[2], boardCords[3]);
				board.nextTurn();
			}
			else if (isMovable == no_invalid) {
				retCode[0] = invalid_piece_move;
			}
			else if (isMovable == no_invalid_will_chess_you) {
				retCode[0] = invalid_will_check_current_player;
			}
			else {
				retCode[0] = unknown_error;
			}

		}

		chessUtills::sendMsg(p, retCode);
		board.draw();
		exit = chessUtills::getMsg(p, &msgFromGraphics);
	}

	delete[] boardCords;
	system("pause");
	return 0;
}
