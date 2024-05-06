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

__int8 const encoder::encode(bool bit) {
	__int8 decodedMsg = this->encodedMsg(bit, this->state);
	this->logLevel(this->state, bit, decodedMsg, this->nextState(bit, this->state));
	this->state = this->nextState(bit, state);
	return decodedMsg;
}

__int8 encoder::encodedMsg(const bool& bit, const __int8& state) {
	return ((((state & 0x1) ^ bit ^ ((state & 0x2) >> 1)) << 1) 
		| (((state & 0x1) ^ bit) | 0x0));
}

__int8 encoder::nextState(const bool &bit, const __int8 &state) {
	return (bit << 1) | ((state & 0x2) >> 1);
}

void encoder::logLevel(const __int8 &state, const bool &bit,
	const __int8 &decoded, const __int8 &nextState) {
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