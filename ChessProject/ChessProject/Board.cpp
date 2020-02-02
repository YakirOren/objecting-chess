#include "Board.h"

Board::Board(std::string startingBoard)
{
	// make 2d array
	this->board = new Piece * *[BOARD_SIZE];

	// parse string to array
	for (int x = 0; x < BOARD_SIZE; x++) {
		this->board[x] = new Piece * [BOARD_SIZE];
		for (int y = 0; y < BOARD_SIZE; y++) {
			char curentChar = startingBoard[(x * BOARD_SIZE) + y];

			switch (tolower(curentChar)) {
			case king:
				this->board[x][y] = new King(x, y, isupper(curentChar) ? black : white);
				break;
			case queen:
				this->board[x][y] = new Queen(x, y, isupper(curentChar) ? black : white);
				break;
			case rook:
				this->board[x][y] = new Rook(x, y, isupper(curentChar) ? black : white);
				break;
			case bishop:
				this->board[x][y] = new Bishop(x, y, isupper(curentChar) ? black : white);
				break;
			case knight:
				this->board[x][y] = new Knight(x, y, isupper(curentChar) ? black : white);
				break;
			case pawn:
				this->board[x][y] = new Pawn(x, y, isupper(curentChar) ? black : white);
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
	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			if (&this->board[x][y] != nullptr)
			{
				delete[] this->board[x][y];
			}
		}
		delete[] this->board[x];
	}
	delete[] this->board;
}

void Board::draw() const
{
	printf("The player turn is: %s \nThe board is:\n", this->playerTurn == white ? "White" : "Black");
	for (int x = 0; x < BOARD_SIZE; x++) {
		for (int y = 0; y < BOARD_SIZE; y++) {
			if (this->board[x][y] == nullptr) {
				printf("%c ", empty);
			}
			else {
				printf("%c ", (*this->board[x][y]).getSymbol());
			}
			
		}
		std::cout << std::endl;
	}
}

int Board::getPlayerTurn() const
{
	return this->playerTurn;
}

Piece* Board::operator()(int dstX, int dstY) const
{
	return this->board[dstX][dstY];
}

void Board::nextTurn()
{
	this->playerTurn = !this->playerTurn;
}

bool Board::updateBoard(int srcX, int srcY, int dstX, int dstY)
{
	bool gotUpdated = false;
	//TODO
	//this->board[dstX][dstY] = this->board[srcX][srcX];
	//delete[] this->board[srcX][srcY];
	//this->board[srcX][srcY] = nullptr;
	return gotUpdated;
}
