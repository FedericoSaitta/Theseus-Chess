#include <iostream>

#include "util.h"
#include "bitboard.h"


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


void parseFEN() {

}