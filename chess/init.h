#pragma once

#include "types.h"
#include "bitboard.h"
#include "attacks.h"

extern Bitboard pawnAttacks[2][64];
extern Bitboard knightAttacks[64];
extern Bitboard kingAttacks[64];

void initAllAttackTables();
