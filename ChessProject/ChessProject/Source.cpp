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
		cout << "Translated msg from GUI: ";
		for (int i = 0; i < 4; i++) {
			cout << boardCords[i];
		}
		cout << endl;

		if ((retCode[0] = chessUtills::isValidCords(board, boardCords[0], boardCords[1], boardCords[2], boardCords[3])) == valid)
		{
			/*
			TODO bonus?
			valid_checkmate = 8,
			*/
			isMovable = board(boardCords[0], boardCords[1])->canMoveTo(board, boardCords[2], boardCords[3]);

			// if canMove returned ok
			if (isMovable == yes_valid) {
				// if it wont check the king next turn
				if (!chessUtills::willCheckNextTurn(board, board.getPlayerTurn() ? white : black, boardCords[0], boardCords[1], boardCords[2], boardCords[3])) {
					retCode[0] = valid;
					board.updateBoard(boardCords[0], boardCords[1], boardCords[2], boardCords[3]);
					board.nextTurn();
				}
				else {
					retCode[0] = invalid_will_check_current_player;
				}
			}
			else if (isMovable == no_invalid) {
				retCode[0] = invalid_piece_move;
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
