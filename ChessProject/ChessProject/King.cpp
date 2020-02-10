#include "King.h"
#include "chessUtills.h"


King::King(const int& x, const int& y, const int& color) : Piece(color, x, y, king) {

}


King::~King()
{
}

int King::canMoveTo(Board& board, const int& dstX, const int& dstY)
{
	// loop over 3x3 around the king
	for (int x = -1; x < 2; x++) {
		for (int y = -1; y < 2; y++) {
			if ((x == 0) && (y == 0)) { // if its not the king
				continue;
			}
			else if (((this->getX() + x) == dstX) && ((this->getY() + y) == dstY) && // if its the position were looking for
				(board(dstX, dstY) == nullptr|| board(dstX, dstY)->getColor() != board(this->getX(), this->getY())->getColor())) { // and its not the same color
				return yes_valid;
			}
		}
	}
	return no_invalid;
}

std::vector<char>* King::isThreatening(Board& board)
{
	std::vector<char>* temp = new std::vector<char>;

	// loop over 3x3 around the king
	for (int x = -1; x < 2; x++) {
		for (int y = -1; y < 2; y++) {
			if (this->getX() + x >= 0 && this->getX() + x < BOARD_SIZE && this->getY() + y >= 0 && this->getY() + y < BOARD_SIZE) { // if its on the board
				if (canMoveTo(board, this->getX() + x, this->getY() + y) && board(this->getX() + x, this->getY() + y)){
					temp->push_back(board((this->getX() + x), (this->getY() + y))->getSymbol());
				}
			}
		}
	}

	return temp;
}
