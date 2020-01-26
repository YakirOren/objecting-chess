#include "Board.h"

Board::Board(std::string startingBoard)
{
	// parse string to array
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			//TODO: fix the operator= error
			char curentChar = startingBoard[(x * BOARD_SIZE) + y];

			switch (tolower(curentChar))
			{
			case king:
				this->board[x][y] = new King(x, y, isupper(curentChar) ? BLACK : WHITE);
				break;
			case queen:
				//this->board[x][y] = new Queen(x, y, isupper(curentChar) ? BLACK : WHITE);
				break;
			case rook:
				this->board[x][y] = new Rook(x, y, isupper(curentChar) ? BLACK : WHITE);
				break;
			case bishop:
				this->board[x][y] = new Bishop(x, y, isupper(curentChar) ? BLACK : WHITE);
				break;
			case knight:
				this->board[x][y] = new Knight(x, y, isupper(curentChar) ? BLACK : WHITE);
				break;
			case pawn:
				//this->board[x][y] = new Pawn(x, y, isupper(curentChar) ? BLACK : WHITE);
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
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++) {
			delete[] this->board[i];
		}
	}
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
	bool gotUpdated = false;
	//TODO
	//this->board[srcX][srcY] = this->board[dstX][dstY];
	//delete[] this->board[dstX][dstY];
	//this->board[dstX][dstY] = nullptr;
	return gotUpdated;
}
