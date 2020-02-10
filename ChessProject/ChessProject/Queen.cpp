#include "Queen.h"

Queen::Queen(const int& x, const int& y, const int& color) : Piece(color, x, y, queen)
{
}

Queen::~Queen()
{
}

int Queen::canMoveTo(Board& board, const int& dstX, const int& dstY)
{
	// this is the rook logic, queen moves like rook and bishop combined
	if ((dstX == this->getX() && dstY != this->getY()) || (dstY == this->getY() && dstX != this->getX())) { // check if the dst is in the line with the queen
		for (int i = this->getY() + 1; i < dstY; i++) { // try to see if she goes up
			if (board(this->getX(), i) != nullptr) {
				return no_invalid;
			}
		}
		for (int i = this->getY() - 1; i > dstY; i--) { // try to see if she goes down
			if (i != dstY && board(this->getX(), i) != nullptr) {
				return no_invalid;
			}
		}
		for (int i = this->getX() + 1; i < dstX; i++) { // try to see if she goes right
			if (board(i, this->getY()) != nullptr) {
				return no_invalid;
			}
		}
		for (int i = this->getX() - 1; i > dstX; i--) { // try to see if she goes left
			if (board(i, this->getY()) != nullptr) {
				return no_invalid;
			}
		}
		if (board(dstX, dstY) != nullptr && // check the dst coords to see if its the same color piece as the src piece if so its invalid
			board(dstX, dstY)->getColor() == board(this->getX(), this->getY())->getColor()) { // and so theres less code duplication
			return no_invalid;
		}
		return yes_valid;
	}
	
	// this is bishop logic
	// if the difference is equal then continue so it will move diagnaly
	if (abs(this->getX() - dstX) != abs(this->getY() - dstY)) {

		return no_invalid;
	}


	// queen to top left
	for (int x = this->getX(), count = 0; (x > dstX) && (this->getY() > dstY); x--, count++)
	{
		if (this->getX() == x) {
			continue;
		}

		if (board(x, this->getY() - count) != nullptr) {

			return no_invalid;
		}
	}


	// queen to bottom left
	for (int x = this->getX(), count = 0; (x < dstX) && (this->getY() > dstY); x++, count++)
	{
		if (this->getX() == x) {
			continue;
		}

		if (board(x, this->getY() - count) != nullptr) {

			return no_invalid;
		}
	}


	// queen to top right
	for (int x = this->getX(), count = 0; (x > dstX) && (this->getY() < dstY); x--, count++)
	{
		if (this->getX() == x) {
			continue;
		}

		if (board(x, this->getY() + count) != nullptr) {

			return no_invalid;
		}
	}


	// queen to bottom right
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

std::vector<char>* Queen::isThreatening(Board& board)
{
	std::vector<char>* threats = new std::vector<char>;
	// this is the rook logic, queen moves like rook and bishop combined
	for (int y = 0; y < BOARD_SIZE; y++) { // look over the collum the queen is on
		if (this->canMoveTo(board, this->getX(), y) == yes_valid && board(this->getX(), y)) { // check if it can move to there and add to threats the piece there
			threats->push_back(board(this->getX(), y)->getSymbol());
		}
	}
	for (int x = 0; x < BOARD_SIZE; x++) { // look over the row the queen is on
		if (this->canMoveTo(board, x, this->getY()) == yes_valid && board(x, this->getY())) { // check if it can move to there and add to threats the piece there
			threats->push_back(board(x, this->getY())->getSymbol());
		}
	}

	// this is bishop logic
	for (int i = 1; i < BOARD_SIZE; i++) {
		int plus_x = this->getX() + i;
		int plus_y = this->getY() + i;
		int minus_x = this->getX() - i;
		int minus_y = this->getY() - i;

		if (minus_y >= 0 && minus_y < BOARD_SIZE) {
			if (plus_x >= 0 && plus_x < BOARD_SIZE) {
				if (canMoveTo(board, this->getX() + i, this->getY() - i) && board(plus_x, minus_y)) { // move to +x -y
					threats->push_back(board(plus_x, minus_y)->getSymbol());
				}
			}
			if (minus_x >= 0 && minus_x < BOARD_SIZE) {
				if (canMoveTo(board, this->getX() - i, this->getY() - i) && board(minus_x, minus_y)) { // move to -x -y
					threats->push_back(board(minus_x, minus_y)->getSymbol());
				}
			}
		}
		if (plus_y >= 0 && plus_y < BOARD_SIZE) {
			if (plus_x >= 0 && plus_x < BOARD_SIZE) {
				if (canMoveTo(board, this->getX() + i, this->getY() + i) && board(plus_x, plus_y)) { // move to +x +y
					threats->push_back(board(plus_x, plus_y)->getSymbol());
				}
			}
			if (minus_x >= 0 && minus_x < BOARD_SIZE) {
				if (canMoveTo(board, this->getX() - i, this->getY() + i) && board(minus_x, plus_y)) { // move to -x +y
					threats->push_back(board(minus_x, plus_y)->getSymbol());
				}
			}
		}
	}
	return threats;
}
