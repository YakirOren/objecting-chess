#pragma once
// This file contain some consts that are used alot

// Pieces
enum colors
{
	white = 0,
	black = 1,
};

enum symbol
{
	king = 'k',
	queen = 'q',
	rook = 'r',
	bishop = 'b',
	knight = 'n',
	pawn = 'p',
	empty = '#',
};

// BOARD
#define BOARD_LAYOUT "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"
#define BOARD_SIZE 8

// move codes
enum moveCodes
{
	valid = '0',
	valid_check = '1',
	invalid_src_is_not_piece = '2',
	invalid_dst_is_current_player = '3',
	invalid_will_check_current_player = '4',
	invalid_index = '5',
	invalid_piece_move = '6',
	invalid_dst_is_src = '7',
	valid_checkmate = '8',
	unknown_error = 'u',
};

// move codes for the canMove method
enum canMoveCodes
{
	yes_valid = 0,
	no_invalid = 1,
	no_invalid_will_chess_you = 1,
};
