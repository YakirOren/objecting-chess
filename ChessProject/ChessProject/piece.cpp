#include "Piece.h"


char Piece::getSymbol()
{
	return this->symbol;
}

/*
get function for the color property
*/
int Piece::getColor()
{
	return this->color;
}

/*
get function for the x cord for this Piece
*/
int Piece::getX()
{
	return this->x;
}

/*
get function for the y cord for this Piece
*/
int Piece::getY()
{
	return this->y;
}

/*
set function for the x,y cords of this Piece
*/
void Piece::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

/*
the constactor function for the Piece class
*/
Piece::Piece(int color, int x, int y)
{
	//TODO get symbol from Enum
	this->color = color;

	this->x = x;
	this->y = y;	
}


Piece::~Piece()
{
}

