#include "decoder.h"
#include <iostream>
#include <bitset>
/*
	// No. of state check
	We have used unsigned __int8 data type value in this simulation,
	it is obvious that it cannot be checked more than 4 times 
	(with 8 bits, 4 bits can be decoded).
*/
#define MAX_STATE_CEHCK 4

decoder::decoder() {
	/* create new object and initial values */
	std::cout << std::endl <<
		"decoder enable"
		<< std::endl;
}

unsigned __int8 decoder::decode(unsigned __int8 recv) {
	std::cout <<  "decoder : " << std::bitset<8>(recv) << std::endl;
	node * n = graphTracer(0,recv,1);
	for (int i = 1; n->getNextFirstStateNode() != nullptr; i++) {
		std::cout << "i : " << i << " | " << std::bitset<8>(n->getNextFirstStateNodeDistance()&0x03) << std::endl;
		std::cout << "i : " << i << " | " << std::bitset<8>(n->getNextScondStateNodeDistance() & 0x03) << std::endl;
		n = n->getNextFirstStateNode();
	}
	return 0;
}

node* decoder::graphTracer(unsigned __int8 state, unsigned __int8 data, unsigned __int8 level){
	// return point | break point of recursive loop
	if (level == MAX_STATE_CEHCK + 2) {
		return nullptr;
	}

	// set next states value
	// -1 == null value | initial value
	unsigned __int8 nextFirstState = -1,
		nextFirstStateIO = -1,
		nextScondState = -1,
		nextScondStateIO = -1;

	switch (state){
		case 0:
			nextFirstState = 0;
			nextFirstStateIO = 0,
			nextScondState = 2,
			nextScondStateIO = 3;
			break;
		case 2:
			nextFirstState = 1;
			nextFirstStateIO = 1,
			nextScondState = 3,
			nextScondStateIO = 2;
			break;
		case 1:
			nextFirstState = 0;
			nextFirstStateIO = 3,
			nextScondState = 2,
			nextScondStateIO = 0;
			break;
		case 3:
			nextFirstState = 1;
			nextFirstStateIO = 2,
			nextScondState = 3,
			nextScondStateIO = 1;
			break;
	}
	node* stateNode = new node(state & 0x03);
	stateNode->setNextFirstStateNode(*this->graphTracer(nextFirstState, data, level + 1));
	stateNode->setNextScondStateNode(*this->graphTracer(nextScondState, data, level + 1));
	stateNode->setNextFirstStateNodeDistance(this->hammingDistance(data,nextFirstStateIO));
	stateNode->setNextScondStateNodeDistance(this->hammingDistance(data,nextScondStateIO));
	return stateNode;
}

unsigned __int8 decoder::hammingDistance(unsigned __int8 x, unsigned __int8 y) {
	__int8 distance = 0;
	unsigned __int8 xorResult = x ^ y; // XOR of the two unsigned __int8
	// Count the number of set bits in the XOR result
	while (xorResult) {
		distance += xorResult & 1;
		xorResult >>= 1;
	}
	return distance;
}

void decoder::logLevel() {
}

decoder :: ~decoder() {
	/* destroy object */
	std::cout << std::endl <<
		"decoder disable"
		<< std::endl;
}