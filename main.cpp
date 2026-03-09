#include <iostream>
#include <cstdint>

#include "chess/bitboard.h"
#include "chess/types.h"
#include "chess/attacks.h"

void printBitboard(Bitboard bb) {
	std::cout << '\n';
	for (int square = 63; square >= 0; --square) {
		if ((square + 1) % 8 == 0) { std::cout << (1 + square / 8) << "| "; }

		std::cout << ((bb >> square) & 1) << ' ';
		if (square % 8 == 0) { std::cout << '\n'; }
	}

	std::cout << "   H G F E D C B A";
	std::cout << '\n';
}


int main() {
	Bitboard test{ 0ULL };
	setBit(test, A7);
	printBitboard(test);
	printBitboard(maskPawnAttacks(BLACK, A7));
}
