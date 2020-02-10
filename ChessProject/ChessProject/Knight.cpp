#include "Knight.h"

Knight::Knight(const int& x, const int& y, const int& color) : Piece(color, x, y, knight)
{
}

Knight::~Knight()
{
}

int Knight::canMoveTo(Board& board, const int& dstX, const int& dstY)
{
	if ((abs(dstY - this->getY()) == 2 && abs(dstX - this->getX()) == 1 ||  // if it goes up or down
		abs(dstX - this->getX()) == 2 && abs(dstY - this->getY()) == 1) && // if it goes left or right
		(board(dstX, dstY) == nullptr || board(dstX, dstY)->getColor() != this->getColor())) { // check if its not the same color
		return yes_valid;
	}
	return no_invalid;
}

std::vector<char>* Knight::isThreatening(Board& board)
{
	std::vector<char>* threats = new std::vector<char>;
	for (int x = this->getX() - 2; x <= this->getX() + 2; x++) { // look over the 5x5 area around the knight
		for (int y = this->getY() - 2; y <= this->getY() + 2; y++) {
			if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && canMoveTo(board, x, y) && board(x, y)) { // check if it can move to there and add a threat if yes
				threats->push_back(board(x, y)->getSymbol());
			}
		}
	}
	return threats;
}


