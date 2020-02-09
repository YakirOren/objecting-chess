#include "Bishop.h"

Bishop::Bishop(const int& x, const int& y, const int& color) : Piece(color, x, y, bishop)
{
}

Bishop::~Bishop()
{
}

int Bishop::canMoveTo(Board& board, const int& dstX, const int& dstY) const
{

	//
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


	return yes_valid;

}

std::vector<char>* Bishop::isThreatening(Board& board) const
{
	std::vector<char>* threats = new std::vector<char>;
	
	// -x -y
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		try
		{
			if (canMoveTo(board, this->getX() - i, this->getY() - i))
			{
				threats->push_back(board(this->getX(), this->getY())->getSymbol());
			}

		}
		catch (...)
		{

		}

	}
	
	// +x -y
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		try
		{
			if (canMoveTo(board, this->getX() + i, this->getY() - i))
			{
				threats->push_back(board(this->getX(), this->getY())->getSymbol());
			}

		}
		catch (...)
		{

		}

	}

	// +x +y
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		try
		{
			if (canMoveTo(board, this->getX() + i, this->getY() + i))
			{
				threats->push_back(board(this->getX(), this->getY())->getSymbol());
			}

		}
		catch (...)
		{

		}

	}

	// -x +y
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		try
		{
			if (canMoveTo(board, this->getX() - i, this->getY() + i))
			{
				threats->push_back(board(this->getX(), this->getY())->getSymbol());
			}

		}
		catch (...)
		{

		}

	}

	return threats;
}
