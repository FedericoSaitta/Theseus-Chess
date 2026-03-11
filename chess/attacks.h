#pragma once 

#include "bitboard.h"

[[nodiscard]] Bitboard maskPawnAttacks(int side, int square);
[[nodiscard]] Bitboard maskKnightAttacks(int square);
[[nodiscard]] Bitboard maskKingAttacks(int square);

[[nodiscard]] Bitboard maskBishopAttacks(int square);
[[nodiscard]] Bitboard maskRookAttacks(int square);
[[nodiscard]] Bitboard bishopAttacksOnTheFly(int square, Bitboard blocker);
[[nodiscard]] Bitboard rookAttacksOnTheFly(int square, Bitboard blocker);