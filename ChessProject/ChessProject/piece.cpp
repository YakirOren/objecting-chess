#include "piece.h"


Piece& Piece::operator= (Piece& other)
{
	this->color = other.getColor();
	this->symbol = other.getSymbol();
	this->x = other.getX();
	this->y = other.getY();

	return *this;
}

/*
get function for the symbol property
*/
char Piece::getSymbol() const
{
	return this->symbol;
}

/*
get function for the color property
*/
int Piece::getColor() const
{
	return this->color;
}

/*
get function for the x cord for this Piece
*/
int Piece::getX() const
{
	return this->x;
}

/*
get function for the y cord for this Piece
*/
int Piece::getY() const
{
	return this->y;
}

/*
set function for this Piece symbol
*/
void Piece::setSymbol(const char symbol)
{
	this->symbol = symbol;
}

/*
set function for the color of this Piece
*/
void Piece::setColor(const int color)
{
	this->color = color;
}


/*
set function for the x,y cords of this Piece
*/
void Piece::setPos(const int x, const int y)
{
	this->x = x;
	this->y = y;
}

/*
the constactor function for the Piece class
*/
Piece::Piece(const int color, const int x , const int y , const char symbol)
{
	//TODO get symbol from Enum
	this->color = color;

	this->x = x;
	this->y = y;
	this->symbol = this->color == white ? tolower(symbol) : toupper(symbol);
}


/*
a constractor function to create an 'empty' piece
*/
Piece::Piece()
{
	this->color = NULL;
	this->x = NULL;
	this->y = NULL;
	this->symbol = NULL;

}


Piece::~Piece()
{
}

