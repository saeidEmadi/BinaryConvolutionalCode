#include "decoder.h"
#include <iostream>
#include <bitset>

decoder::decoder() {
	/* create new object and initial values */
	std::cout << std::endl <<
		"decoder enable"
		<< std::endl;
}

__int8 decoder::decode(__int8 recv) {
	int a[4][2] = { {0,2},{0,2},{1,3},{1,3} };

	//this->distanceCal(0, 0, recv);
	//for (int i = 0; i < 4; i++) {
	//	// rows = 00 , 10, 01, 11
	//	__int8 bit = (recv & 0xE0) >> 6;
	//	for (int j = 0; j < rout[i].size(); j++) {
	//		for (int k = 0; k < 2; k++) {
	//			std::cout << static_cast<int>(this->hammingDistance(a[j][k],bit)) << std::endl;
	//		}
	//	}
	//	std::cout << "new colml" << std::endl;
	//	recv = (recv << 2);
	//}
	return 0;
}

__int8 decoder::distanceCal(int level, __int8 state, __int8 bit) {
	/*
	if (level == 5) {
		return 0;
	}
	switch(state){
		case 0:
			std::cout << this->distanceCal(level + 1, 0, (bit << 2) & 0xE0) + this->hammingDistance(state, (bit & 0xE0) >> 6) << std::endl;
			std::cout << this->distanceCal(level + 1, 2, (bit << 2) & 0xE0) + this->hammingDistance(state, (bit & 0xE0) >> 6) << std::endl;
			break;
		case 1:
			std::cout << this->distanceCal(level + 1, 0, (bit << 2) & 0xE0) + this->hammingDistance(state, (bit & 0xE0) >> 6) << std::endl;
			std::cout << this->distanceCal(level + 1, 2, (bit << 2) & 0xE0) + this->hammingDistance(state, (bit & 0xE0) >> 6) << std::endl;
			break;
		case 2:
			std::cout << this->distanceCal(level + 1, 1, (bit << 2) & 0xE0) + this->hammingDistance(state, (bit & 0xE0) >> 6) << std::endl;
			std::cout << this->distanceCal(level + 1, 3, (bit << 2) & 0xE0) + this->hammingDistance(state, (bit & 0xE0) >> 6) << std::endl;
			break;
		case 3:
			std::cout << this->distanceCal(level + 1, 1, (bit << 2) & 0xE0) + this->hammingDistance(state, (bit & 0xE0) >> 6) << std::endl;
			std::cout << this->distanceCal(level + 1, 3, (bit << 2) & 0xE0) + this->hammingDistance(state, (bit & 0xE0) >> 6) << std::endl;
			break;
	default:
		break;
	}
	*/
	return 0;
}
__int8 decoder::hammingDistance(__int8 x, __int8 y) {
	int distance = 0;
	int xorResult = x ^ y; // XOR of the two integers
	// Count the number of set bits in the XOR result
	while (xorResult) {
		distance += xorResult & 1;
		xorResult >>= 1;
	}
	return distance;
}

void decoder::logLevel(__int8 state, __int8 recv, __int8 decoded, __int8 nextState) {
	std::cout << std::endl <<
		"[---- bit log ----]" << std::endl <<
		"  state : " << std::bitset<2>(state) << std::endl <<
		"  nextState : " << std::bitset<2>(nextState) << std::endl <<
		"  recv : " << std::bitset<1>(recv) << std::endl <<
		"  encoded : " << std::bitset<2>(decoded) << std::endl <<
		"[----         ----]" << std::endl;
}

decoder :: ~decoder() {
	/* destroy object */
	std::cout << std::endl <<
		"decoder disable"
		<< std::endl;
}