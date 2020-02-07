#include "Queen.h"

Queen::Queen(const int& x, const int& y, const int& color) : Piece(color, x, y, queen)
{
}

Queen::~Queen()
{
}

int Queen::canMoveTo(Board& board, const int& dstX, const int& dstY) const
{
	if ((dstX == this->getX() && dstY != this->getY()) ||
		(dstY == this->getY() && dstX != this->getX())
		/*insert bishop logic here*/) {
		for (int i = this->getY() + 1; i < dstY; i++) {
			if (board(this->getX(), i) != nullptr) {
				return no_invalid;
			}
		}
		for (int i = this->getY() - 1; i > dstY; i--) {
			if (i != dstY && board(this->getX(), i) != nullptr) {
				return no_invalid;
			}
		}
		for (int i = this->getX() + 1; i < dstX; i++) {
			if (board(i, this->getY()) != nullptr) {
				return no_invalid;
			}
		}
		for (int i = this->getX() - 1; i > dstX; i--) {
			if (board(i, this->getY()) != nullptr) {
				return no_invalid;
			}
		}
		if (board(dstX, dstY) != nullptr && board(dstX, dstY)->getColor() == board(this->getX(), this->getY())->getColor()) {
			return no_invalid;
		}
	}
	else {
		return no_invalid;
	}

	return yes_valid;
}

std::vector<char>* Queen::isThreatening(Board& board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}
