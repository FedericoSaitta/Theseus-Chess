#include "init.h"
#include "bitboard.h"
#include "attacks.h"
#include "types.h"
#include "util.h"

#include <iostream>

Bitboard pawnAttacks[2][64];
Bitboard knightAttacks[64];
Bitboard kingAttacks[64];


void initLeaperAttacks() {
	for (int sq = 0; sq < 64; sq++) {
		pawnAttacks[Side::WHITE][sq] = maskPawnAttacks(Side::WHITE, sq);
		pawnAttacks[Side::BLACK][sq] = maskPawnAttacks(Side::BLACK, sq);

		knightAttacks[sq] = maskKnightAttacks(sq);
		kingAttacks[sq] = maskKingAttacks(sq);
	}
}



void initAllAttackTables() {
	initLeaperAttacks();
}