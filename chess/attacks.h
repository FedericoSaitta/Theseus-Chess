#pragma once 

#include "bitboard.h"

[[nodiscard]] Bitboard maskPawnAttacks(int side, int square);
[[nodiscard]] Bitboard maskKnightAttacks(int square);
[[nodiscard]] Bitboard maskKingAttacks(int square);