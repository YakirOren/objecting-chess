#include "piece.h"


char piece::getSymbol()
{
	return this->symbol;
}

/*
get function for the color property
*/
int piece::getColor()
{
	return this->color;
}

/*
get function for the x cord for this piece
*/
int piece::getX()
{
	return this->x;
}

/*
get function for the y cord for this piece
*/
int piece::getY()
{
	return this->y;
}

/*
set function for the x,y cords of this piece
*/
void piece::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

/*
the constactor function for the piece class
*/
piece::piece(int color, int x, int y)
{
	//TODO get symbol from Enum
	this->color = color;

	this->x = x;
	this->y = y;	
}


piece::~piece()
{
}


