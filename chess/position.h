#pragma once

#include "bitboard.h"
#include "types.h"

struct Position {
	Bitboard pieces[12]; 
	Bitboard occupancies[3];

	Side sideToMove;
};