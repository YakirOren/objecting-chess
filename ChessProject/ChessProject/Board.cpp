#include "Board.h"

Board::Board(std::string startingBoard)
{
	// make the 2d array
	this->board = new char*[BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++){
		this->board[i] = new char[BOARD_SIZE];
	}

	// parse string to array
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			//TODO: make enum of pieces that show their char and make pieces objects
		}
	}

	// set the player turn
	this->playerTurn = atoi(&startingBoard[BOARD_SIZE * BOARD_SIZE]);
}

Board::~Board()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		delete[] this->board[i];
	}
	delete[] this->board;
}

void Board::draw()
{
	printf("The player turn is: %d and the board is:\n", this->playerTurn);
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			std::cout << this->board[x][y].getSymbol();
		}
		std::cout << std::endl;
	}
}

int Board::getPlayerTurn()
{
	return this->playerTurn;
}

bool Board::updateBoard(std::string newPos)
{
	//TODO
	return false;
}
