#include "King.h"


King::King(int x, int y, int color) : Piece(color, x, y, king){

}


King::~King()
{
}

bool King::canMoveTo(Board board, int dstX, int dstY) const
{
    /*
    TODO: check if the king is not being threatened in the dst pos

    implemnted in board??
    */

    bool canMove = false;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if ((i == 0) && (j == 0))
            {
                continue;
            }
            else if (((this->getX() + i) == dstX) && ((this->getY() + j) == dstY)) {
                canMove = true;
            }
        }
    }


    return canMove;
}

bool King::isCheck(Board board) const
{
	return false;
}

std::vector<char>* King::isThreatening(Board board) const
{
	std::vector<char>* temp = new std::vector<char>;
	return temp;
}

void King::draw() const
{
}
