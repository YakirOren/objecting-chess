#include "Bishop.h"

Bishop::Bishop(const int& x, const int& y, const int& color) : Piece(color, x, y, bishop)
{
}

Bishop::~Bishop()
{
}

int Bishop::canMoveTo(Board& board, const int& dstX, const int& dstY)
{

	// if the difference is equal then continue so it will move diagnaly
	if (abs(this->getX() - dstX) != abs(this->getY() - dstY)) {

		return no_invalid;
	}


	//bishop to top left
	for (int x = this->getX(), count = 0; (x > dstX) && (this->getY() > dstY); x--, count++)
	{
		if (this->getX() == x) {
			continue;
		}

		if (board(x, this->getY() - count) != nullptr) {

			return no_invalid;
		}
	}


	//bishop to bottom left
	for (int x = this->getX(), count = 0; (x < dstX) && (this->getY() > dstY); x++, count++)
	{
		if (this->getX() == x) {
			continue;
		}

		if (board(x, this->getY() - count) != nullptr) {

			return no_invalid;
		}
	}


	//bishop to top right
	for (int x = this->getX(), count = 0; (x > dstX) && (this->getY() < dstY); x--, count++)
	{
		if (this->getX() == x) {
			continue;
		}

		if (board(x, this->getY() + count) != nullptr) {

			return no_invalid;
		}
	}


	//bishop to bottom right
	for (int x = this->getX(), count = 0; (x < dstX) && (this->getY() < dstY); x++, count++)
	{
		if (this->getX() == x) {
			continue;
		}

		if (board(x, this->getY() + count) != nullptr) {

			return no_invalid;
		}
	}

	if (board(dstX, dstY) && board(dstX, dstY)->getColor() == this->getColor()) {
		return no_invalid;
	}

	return yes_valid;

}

std::vector<char>* Bishop::isThreatening(Board& board)
{
	std::vector<char>* threats = new std::vector<char>;

	for (int i = 1; i < BOARD_SIZE; i++) {
		int plus_x = this->getX() + i;
		int plus_y = this->getY() + i;
		int minus_x = this->getX() - i;
		int minus_y = this->getY() - i;

		if (minus_y >= 0 && minus_y < BOARD_SIZE) {
			if (plus_x >= 0 && plus_x < BOARD_SIZE) {
				if (canMoveTo(board, this->getX() + i, this->getY() - i) && board(plus_x, minus_y)) { // move to +x -y
					printf("DEBUG[bishop] isthreat -> %d, %d has %c\n", plus_x, minus_y, board(plus_x, minus_y)->getSymbol());
					threats->push_back(board(plus_x, minus_y)->getSymbol());
				}
			}
			if (minus_x >= 0 && minus_x < BOARD_SIZE) {
				if (canMoveTo(board, this->getX() - i, this->getY() - i) && board(minus_x, minus_y)) { // move to -x -y
					printf("DEBUG[bishop] isthreat -> %d, %d has %c\n", minus_x, minus_y, board(minus_x, minus_y)->getSymbol());
					threats->push_back(board(minus_x, minus_y)->getSymbol());
				}
			}
		}
		if (plus_y >= 0 && plus_y < BOARD_SIZE) {
			if (plus_x >= 0 && plus_x < BOARD_SIZE) {
				if (canMoveTo(board, this->getX() + i, this->getY() + i) && board(plus_x, plus_y)) { // move to +x +y
					printf("DEBUG[bishop] isthreat -> %d, %d has %c\n", plus_x, plus_y, board(plus_x, plus_y)->getSymbol());
					threats->push_back(board(plus_x, plus_y)->getSymbol());
				}
			}
			if (minus_x >= 0 && minus_x < BOARD_SIZE) {
				if (canMoveTo(board, this->getX() - i, this->getY() + i) && board(minus_x, plus_y)) { // move to -x +y
					printf("DEBUG[bishop] isthreat -> %d, %d has %c\n", minus_x, plus_y, board(minus_x, plus_y)->getSymbol());
					threats->push_back(board(minus_x, plus_y)->getSymbol());
				}
			}
		}
	}

	return threats;
}
