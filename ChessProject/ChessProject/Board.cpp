#include "Board.h"
#include "ath.h"

Board::Board(std::string startingBoard)
{
	// make 2d array
	this->board = new Piece * *[BOARD_SIZE];

	// parse string to array
	for (int x = 0; x < BOARD_SIZE; x++) {
		this->board[x] = new Piece * [BOARD_SIZE];
		for (int y = 0; y < BOARD_SIZE; y++) {
			char curentChar = startingBoard[((int)x * BOARD_SIZE) + y];

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

/*
	this function is checking if the pieces in the given color
	are threatening on the other color in other words, the player has check on the other player
*/
bool Board::isThereCheckForColor(int color)
{
	bool check = false;
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)//looping over all the pieces in the board 
		{
			if (this->board[x][y] != nullptr) // checking that the slot we are working on is not empty
			{
				if (((*this->board[x][y]).getColor()) == color) // getting only the pieces with the color we want
				{
					std::vector<char>* threats = this->board[x][y]->isThreatening(*this); // getting a vector of all the pieces that are being threated by the piece   
					for (int i = 0; i < threats->size(); i++)//looping over all elements in the vector 
					{
						if (((*threats)[i] == 'k') || ((*threats)[i] == 'K')) // checking if anyone of them is a king
						{
							check = true; // we found that a piece somewhere on the board is threatening on a king in other words, getting check.
						}
					}
					delete[] threats; // freeing the memory (the vector was alloceted with new so it needs to be freed) 
				}

			}
		}
	}

	return check;
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
	if (this->board[dstX][dstY] != nullptr)
	{
		delete[] this->board[dstX][dstY];
	}
	this->board[dstX][dstY] = this->board[srcX][srcX];
	this->board[srcX][srcY] = nullptr;
	return gotUpdated;
}
