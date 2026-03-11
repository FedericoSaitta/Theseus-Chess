#include <iostream>
#include <cstdint>

#include "chess/bitboard.h"
#include "chess/types.h"
#include "chess/attacks.h"
#include "chess/init.h"

#include "tests/test.h"


int main() {
	initAllAttackTables();	

	Bitboard test{ 0ULL };
	setBit(test, Square::A1);

	std::cout << getLSB(test);


	// Test::visualizeLeaperAttackTables();
	Test::visualizeOccupancyTables();

}
