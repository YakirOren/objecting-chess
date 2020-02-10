#include "Rook.h"

Rook::Rook(const int& x, const int& y, const int& color) : Piece(color, x, y, rook)
{


}

int Rook::canMoveTo(Board& board, const int& dstX, const int& dstY)
{
	//TODO check if the king will be in check after move ad return acordingly
	if ((dstX == this->getX() && dstY != this->getY()) || (dstY == this->getY() && dstX != this->getX())) { // check if the dst is in the line with the rook
		for (int i = this->getY() + 1; i < dstY; i++) { // try to see if he goes up
			if (board(this->getX(), i) != nullptr) {
				return no_invalid;
			}
		}
		for (int i = this->getY() - 1; i > dstY; i--) { // try to see if he goes down
			if (i != dstY && board(this->getX(), i) != nullptr) {
				return no_invalid;
			}
		}
		for (int i = this->getX() + 1; i < dstX; i++) { // try to see if he goes right
			if (board(i, this->getY()) != nullptr) {
				return no_invalid;
			}
		}
		for (int i = this->getX() - 1; i > dstX; i--) { // try to see if he goes left
			if (board(i, this->getY()) != nullptr) {
				return no_invalid;
			}
		}
		if (board(dstX, dstY) != nullptr && // check the dst coords to see if its the same color piece as the src piece if so its invalid
			board(dstX, dstY)->getColor() == board(this->getX(), this->getY())->getColor()) { // and so theres less code duplication
			return no_invalid;
		}
	}
	else {
		return no_invalid;
	}

	return yes_valid;
}

std::vector<char>* Rook::isThreatening(Board& board)
{
	std::vector<char>* threats = new std::vector<char>;
	for (int y = 0; y < BOARD_SIZE; y++) { // look over the collum the rook is on
		if (this->canMoveTo(board, this->getX(), y) && board(this->getX(), y)) { // check if it can move to there and add to threats the piece there
			threats->push_back(board(this->getX(), y)->getSymbol());
		}
	}
	for (int x = 0; x < BOARD_SIZE; x++) { // look over the row the rook is on
		if (this->canMoveTo(board, x, this->getY() && board(x, this->getY()))) { // check if it can move to there and add to threats the piece there
			threats->push_back(board(x, this->getY())->getSymbol());
		}
	}
	return threats;
}

Rook::~Rook()
{
	
}


