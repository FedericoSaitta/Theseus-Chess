#include "test.h"
#include "../chess/util.h"
#include "../chess/attacks.h"
#include "../chess/init.h"

#include <iostream>

void Test::visualizeLeaperAttackTables() {
	for (int sq = 0; sq < 64; sq++) {
		std::cout << "Square: " << sq << std::endl;
		std::cout << "White Pawn: " << sq << std::endl;
		printBitboard(maskPawnAttacks(Side::WHITE, sq));
		std::cout << "Black Pawn: " << sq << std::endl;
		printBitboard(maskPawnAttacks(Side::BLACK, sq));

		std::cout << "Knight: " << sq << std::endl;
		printBitboard(maskKnightAttacks(sq));
		std::cout << "King: " << sq << std::endl;
		printBitboard(maskKingAttacks(sq));
	}
}

void Test::visualizeOccupancyTables() {
	for (int sq = 0; sq < 64; sq++) {
		std::cout << "Square: " << sq << std::endl;
		std::cout << "Bishop: " << sq << std::endl;
		printBitboard(maskBishopAttacks(sq));
		std::cout << "Rook: " << sq << std::endl;
		printBitboard(maskRookAttacks(sq));
	}
}