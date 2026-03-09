#pragma once

#include <cstdint>
#include <cassert>
#include <cstdlib>
#include <intrin0.inl.h>

using Bitboard = std::uint64_t;

constexpr Bitboard notAFile{ 18374403900871474942ULL };
constexpr Bitboard notHFile{ 9187201950435737471ULL };
constexpr Bitboard notHGFile{ 4557430888798830399ULL };
constexpr Bitboard notABFile{ 18229723555195321596ULL };

inline void setBit(Bitboard& bb, const int square) { bb |= (1ULL << square); }
inline void popBit(Bitboard& bb, const int square) { bb &= ~(1ULL << square); }

[[nodiscard]] inline bool getBit(Bitboard bb, const int square) {
	return bb & (1ULL << square);
}

[[nodiscard]] inline int getLSB(Bitboard bb) {
	assert(bb);
	unsigned long idx;
	_BitScanForward64(&idx, bb);
	return static_cast<int>(idx);
}

[[nodiscard]] inline int popLSB(Bitboard& bb) {
	assert(bb);
	int square{ getLSB(bb) };
	bb &= bb - 1;
	return square;
}

[[nodiscard]] inline int countBits(const Bitboard bb) {
	return static_cast<int>(__popcnt64(bb));
}

inline Bitboard mirrorVertical(Bitboard bb) {
	return _byteswap_uint64(bb);
}

inline Bitboard mirrorHorizontal(Bitboard bb) {
	const Bitboard k1 = 0x5555555555555555ULL;
	const Bitboard k2 = 0x3333333333333333ULL;
	const Bitboard k4 = 0x0F0F0F0F0F0F0F0FULL;
	bb = ((bb >> 1) & k1) | ((bb & k1) << 1);  // swap adjacent bits
	bb = ((bb >> 2) & k2) | ((bb & k2) << 2);  // swap bit pairs
	bb = ((bb >> 4) & k4) | ((bb & k4) << 4);  // swap nibbles
	return bb;
}