#include <iostream>
#include <cstdint>

#include "chess/bitboard.h"
#include "chess/types.h"

void printBitboard(Bitboard bb) {

	for (int i = 63; i >= 0; i--) {
		bool isBitSet{ static_cast<bool>((bb >> i) & 1ULL) };
		if (isBitSet)
		{
			std::cout << "1 ";
		}
			
		else
		{
			std::cout << "0 ";
		}

		if (i % 8 == 0)
		{
			std::cout << '\n';
		}
	}

	std::cout << "H G F E D C B A" << std::endl;
}


int main() {
	printBitboard(notHFile);
	std::cout << countBits(notHFile) << std::endl;

	std::cout << getLSB(notAFile) << std::endl;

	Bitboard test{ 23402340 }; 
	printBitboard(test);
	printBitboard(mirrorHorizontal(test));
	printBitboard(mirrorVertical(test));
}
