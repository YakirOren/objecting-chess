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

	Pipe* p = chessUtills::initBoard();
	if (p == nullptr) {
		system("pause");
		return 0;
	}

	Board* board = new Board(BOARD_LAYOUT);
	bool exit = false;
	char currentChar = 'a';
	int isMovable = 0;
	string msgFromGraphics = p->getMessageFromGraphics();
	int* boardCords = new int[4]; // [src x, src y, dst x, dst y]
	string retCode = "1";

	//game loop
	while (msgFromGraphics != "quit")
	{
		chessUtills::parseGuiResponse(msgFromGraphics, boardCords);
		cout << "Translated msg from GUI: ";
		for (int i = 0; i < 4; i++) {
			cout << boardCords[i];
		}
		cout << endl;

		if ((retCode[0] = chessUtills::isValidCords(*board, boardCords[0], boardCords[1], boardCords[2], boardCords[3])) == valid)
		{
			isMovable = (*board)(boardCords[0], boardCords[1])->canMoveTo(*board, boardCords[2], boardCords[3]);

			// if canMove returned ok
			if (isMovable == yes_valid) {
				// if it wont check the king next turn
				if (!chessUtills::willCheckNextTurn(*board, board->getPlayerTurn() ? colors::white : colors::black, boardCords[0], boardCords[1], boardCords[2], boardCords[3])) {
					board->updateBoard(boardCords[0], boardCords[1], boardCords[2], boardCords[3], true);
					if (chessUtills::isThereCheckForColor(*board, board->getPlayerTurn())) {
						if (chessUtills::isCheckMate(*board, board->getPlayerTurn())) {
							retCode[0] = valid_checkmate;
						}
						else {
							retCode[0] = valid_check;
						}
					}
					else {
						retCode[0] = valid;
					}
					board->nextTurn();
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
		board->draw();
		chessUtills::getMsg(p, &msgFromGraphics);
	}

	p->close();
	delete board;
	delete[] boardCords;
	return 0;
}
