#pragma once
// This file contain some consts that are used alot

// Pieces
#define WHITE 0
#define BLACK 1

// BOARD
#define LAYOUT "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"
#define BOARD_SIZE 8

// move codes
#define VALID 0
#define VALID_CHECK 1
#define INVALID_Piece_NOT_ON_SRC 2
#define INVALID_DST_IS_CURRENT_PLAYER 3
#define INVALID_WILL_CHECK_CURRENT_PLAYER 4
#define INVALID_INDEX 5
#define INVALID_Piece_MOVE 6
#define INVALID_DST_IS_SRC 7
#define VALID_CHECKMATE 8

enum symbol
{
	king = 'k',
	queen = 'q',
	rook = 'r',
	bishop = 'b',
	knight = 'n',
	pawn = 'p',
};