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

Bitboard maskKnightAttacks(int square) {
	Bitboard attacks{ 0ULL };
	Bitboard bb{ 0ULL };

	setBit(bb, square);

	// RHS
	if ((bb << 6) & notHGFile) { attacks |= (bb << 6); }
	if ((bb << 15) & notHFile) { attacks |= (bb << 15); }
	if ((bb >> 10) & notHGFile) { attacks |= (bb >> 10); }
	if ((bb >> 17) & notHFile) { attacks |= (bb >> 17); }

	// LHS
	if ((bb >> 6) & notABFile) { attacks |= (bb >> 6); }
	if ((bb >> 15) & notAFile) { attacks |= (bb >> 15); }
	if ((bb << 10) & notABFile) { attacks |= (bb << 10); }
	if ((bb << 17) & notAFile) { attacks |= (bb << 17); }

	return attacks;
}


Bitboard maskKingAttacks(int square) {
	Bitboard attacks{ 0ULL };
	Bitboard bb{ 0ULL };

	setBit(bb, square);

	// RHS + North
	if ((bb >> 1) & notHFile) { attacks |= (bb >> 1); }
	if ((bb >> 9) & notHFile) { attacks |= (bb >> 9); }
	if ((bb << 7) & notHFile) { attacks |= (bb << 7); }
	attacks |= (bb << 8);

	// LHS + South
	if ((bb << 1) & notAFile) { attacks |= (bb << 1); }
	if ((bb << 9) & notAFile) { attacks |= (bb << 9); }
	if ((bb >> 7) & notAFile) { attacks |= (bb >> 7); }
	attacks |= (bb >> 8);

	return attacks;
}