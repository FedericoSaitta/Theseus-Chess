#include "attacks.h"
#include "bitboard.h"

Bitboard maskPawnAttacks(int side, int square)
{
	Bitboard attacks{ 0ULL };
	Bitboard bb{ 0ULL };

	setBit(bb, square); 

	// white pawns
	if (!side) {
		if ((bb << 7) & notHFile) { attacks |= (bb << 7); }
		if ((bb << 9) & notAFile) { attacks |= (bb << 9); }
	}
	// black pawns
	else {
		if ((bb >> 7) & notAFile) { attacks |= (bb >> 7); }
		if ((bb >> 9) & notHFile) { attacks |= (bb >> 9); }
	}

	return attacks;
}