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
	std::cout << "decoder : " << std::bitset<8>(recv) << std::endl;
	node* m = graphTracer(0, recv, 1);
	node* n = getMinDistancePaths(0, recv, 1);
	printStates(m);
	std::cout << "\nmin dis :: " << std::bitset<8>(printStatesMinPath(n));
	/*for (int i = 1; n->getNextFirstStateNode() != nullptr; i++) {
		std::cout << "i : " << i << " | " << std::bitset<8>(n->getNextFirstStateNodeDistance()&0x03) << std::endl;
		std::cout << "i : " << i << " | " << std::bitset<8>(n->getNextScondStateNodeDistance() & 0x03) << std::endl;
		n = n->getNextFirstStateNode();
	}*/
	return 0;
}

__int8 decoder::printStatesMinPath(node* n) {
	unsigned __int8 nextFirstStateIO = -1,
		nextScondStateIO = -1;

	switch (n->getState()) {
	case 0:
		nextFirstStateIO = 0,
			nextScondStateIO = 3;
		break;
	case 2:
		nextFirstStateIO = 1,
			nextScondStateIO = 2;
		break;
	case 1:
		nextFirstStateIO = 3,
			nextScondStateIO = 0;
		break;
	case 3:
		nextFirstStateIO = 2,
			nextScondStateIO = 1;
		break;
	}
	if (n->getNextFirstStateNode() == nullptr && n->getNextScondStateNode() == nullptr) {
		return 0;
	}
	else if (n->getNextFirstStateNode() != nullptr && n->getNextScondStateNode() == nullptr) {
		//std::cout << "getNextFirstStateNode()->getState() :: " << std::bitset<8>(n->getNextFirstStateNode()->getState()) << std::endl;
		return this->printStatesMinPath(n->getNextFirstStateNode()) + n->getNextFirstStateNodeDistance();
	}
	else if (n->getNextScondStateNode() != nullptr && n->getNextFirstStateNode() == nullptr) {
		// std::cout << "getNextScondStateNode()->getState() :: " << std::bitset<8>(n->getNextScondStateNode()->getState()) << std::endl;
		return this->printStatesMinPath(n->getNextScondStateNode()) + n->getNextScondStateNodeDistance();
	}
	else if (n->getNextScondStateNode() != nullptr && n->getNextFirstStateNode() != nullptr) {
		if (n->getNextScondStateNodeDistance() > n->getNextFirstStateNodeDistance()) {
			return this->printStatesMinPath(n->getNextFirstStateNode()) + n->getNextFirstStateNodeDistance();
		}
		else if (n->getNextScondStateNodeDistance() < n->getNextFirstStateNodeDistance()) {
			return this->printStatesMinPath(n->getNextScondStateNode()) + n->getNextScondStateNodeDistance();
		}
		else {
			int d1 = this->printStatesMinPath(n->getNextFirstStateNode()) + n->getNextFirstStateNodeDistance();
			int d2 = this->printStatesMinPath(n->getNextScondStateNode()) + n->getNextScondStateNodeDistance();
			if (d1 > d2) {
				return d2;
			}
			else {
				return d1;
			}
		}
	}
}

void decoder::printStates(node* n) {
	if (n->getNextFirstStateNode() == nullptr || n->getNextScondStateNode() == nullptr) {
		return;
	}
	std::cout << "state : " << std::bitset<8>(n->getState()) << std::endl;
	std::cout << "NextFirstStateNodeDistance : " << std::bitset<8>(n->getNextFirstStateNodeDistance() & 0x03) << std::endl;
	std::cout << "NextScondStateNodeDistance : " << std::bitset<8>(n->getNextScondStateNodeDistance() & 0x03) << std::endl;
	std::cout << "getNextFirstStateNode()->getState() : " << std::bitset<8>(n->getNextFirstStateNode()->getState()) << std::endl;
	std::cout << "getNextScondStateNode()->getState() : " << std::bitset<8>(n->getNextScondStateNode()->getState()) << std::endl;
	this->printStates(n->getNextFirstStateNode());
	this->printStates(n->getNextScondStateNode());
}

node* decoder::getMinDistancePaths(unsigned __int8 state, unsigned __int8 data, unsigned __int8 level) {
	// return point | break point of recursive loop
	if (level == MAX_STATE_CEHCK + 2) {
		return nullptr;
	}

	// data shifter : shift in each level
	__int8 shiftVal = 0;
	switch (level) {
	case 1:
		shiftVal = 6;
		break;
	case 2:
		shiftVal = 4;
		break;
	case 3:
		shiftVal = 2;
		break;
	case 4:
		shiftVal = 0;
		break;
	default:
		shiftVal = 0;
		break;
	}


	// set next states value
	// -1 == null value | initial value
	unsigned __int8 nextFirstState = -1,
		nextFirstStateIO = -1,
		nextScondState = -1,
		nextScondStateIO = -1;

	switch (state) {
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
	stateNode->setNextFirstStateNodeDistance(this->hammingDistance((data >> shiftVal) & 0x03, nextFirstStateIO));
	stateNode->setNextScondStateNodeDistance(this->hammingDistance((data >> shiftVal) & 0x03, nextScondStateIO));
	if (stateNode->getNextFirstStateNodeDistance() > stateNode->getNextScondStateNodeDistance()) {
		stateNode->setNextScondStateNode(*this->getMinDistancePaths(nextScondState, data, level + 1));
	}
	else if (stateNode->getNextFirstStateNodeDistance() < stateNode->getNextScondStateNodeDistance()) {
		stateNode->setNextFirstStateNode(*this->getMinDistancePaths(nextFirstState, data, level + 1));
	}
	else {
		stateNode->setNextFirstStateNode(*this->getMinDistancePaths(nextFirstState, data, level + 1));
		stateNode->setNextScondStateNode(*this->getMinDistancePaths(nextScondState, data, level + 1));
	}
	return stateNode;
}

node* decoder::graphTracer(unsigned __int8 state, unsigned __int8 data, unsigned __int8 level) {
	// return point | break point of recursive loop
	if (level == MAX_STATE_CEHCK + 2) {
		return nullptr;
	}

	// data shifter : shift in each level
	__int8 shiftVal = 0;
	switch (level) {
	case 1:
		shiftVal = 6;
		break;
	case 2:
		shiftVal = 4;
		break;
	case 3:
		shiftVal = 2;
		break;
	case 4:
		shiftVal = 0;
		break;
	default:
		shiftVal = 0;
		break;
	}


	// set next states value
	// -1 == null value | initial value
	unsigned __int8 nextFirstState = -1,
		nextFirstStateIO = -1,
		nextScondState = -1,
		nextScondStateIO = -1;

	switch (state) {
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
	stateNode->setNextFirstStateNodeDistance(this->hammingDistance((data >> shiftVal) & 0x03, nextFirstStateIO));
	stateNode->setNextScondStateNodeDistance(this->hammingDistance((data >> shiftVal) & 0x03, nextScondStateIO));
	return stateNode;
}

unsigned __int8 decoder::hammingDistance(unsigned __int8 x, unsigned __int8 y) {
	__int8 distance = 0;
	unsigned __int8 xorResult = x ^ y; // XOR of the two unsigned __int8
	// Count the number of set bits in the XOR result
	while (xorResult > 0) {
		distance += xorResult & 1;
		xorResult >>= 1;
	}
	return distance - 1;
}

void decoder::logLevel() {
}

decoder :: ~decoder() {
	/* destroy object */
	std::cout << std::endl <<
		"decoder disable"
		<< std::endl;
}