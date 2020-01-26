#include "Board.h"

Board::Board(std::string startingBoard)
{
	// make the 2d array
	this->board = new Piece * [BOARD_SIZE];
	for (int i = 0; i < BOARD_SIZE; i++) {
		this->board[i] = new Piece[BOARD_SIZE]();
	}

	// parse string to array
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			//TODO: fix all of this logic
			char curentChar = startingBoard[(x * BOARD_SIZE) + y];

			switch (tolower(curentChar))
			{
			case king:
				break;
			case queen:
				break;
			case rook:
				break;
			case Bishop:
				break;
			case knight:
				break;
			case pawn:
				break;
			default:
				this->board[x][y] = nullptr;
				break;
			}
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

Piece Board::getSlot(int dstX, int dstY)
{
	return this->board[dstX][dstY];
}

bool Board::updateBoard(int srcX, int srcY, int dstX, int dstY)
{
	//TODO
	this->board[srcX][srcY] = this->board[dstX][dstY];
	delete this->board[dstX][dstY];
	this->board[dstX][dstY] = nullptr;
	return false;
}
