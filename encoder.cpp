#include "encoder.h"
#include <iostream>
#include <bitset>

encoder::encoder() {
	/* create new object and initial values : 
		- state = 00
	*/
	std::cout << std::endl <<
		"encoder enable"
		<< std::endl;
	state = 0;
}

__int8 encoder::encode(bool bit) {
	__int8 c2 = (state & 0x1) ^ bit;
	__int8 c1 = ((state & 0x1) ^ bit ^ ((state & 0x2) >> 1));
	this->logLevel(this->state, bit,((c1 << 1) | (c2 | 0x0)),(bit << 1) | ((state & 0x2) >> 1));
	this->state = (bit << 1) | ((state & 0x2) >> 1);
	return ((c1 << 1) | (c2 | 0x0));
}

void encoder::logLevel(__int8 state, bool bit, __int8 decoded, __int8 nextState) {
	std::cout << std::endl <<
		"[---- bit log ----]" << std::endl <<
		"  state : " << std::bitset<2>(state) << std::endl <<
		"  nextState : " << std::bitset<2>(nextState) << std::endl <<
		"  bit : " << std::bitset<1>(bit) << std::endl <<
		"  decoded : " << std::bitset<2>(decoded) << std::endl <<
		"[----         ----]" << std::endl;
}

encoder :: ~encoder() {
	/* destroy object */
	std::cout << std::endl <<
		"encoder disable"
		<< std::endl;
}