#include "encoder.h"
#include <iostream>
#include <bitset>

encoder::encoder() {
	/* create new object and initial values : 
		- state = 00
	*/
	std::cout <<
		"encoder enable"
		<< std::endl;
	state = 0;
}

void encoder::logLevel(__int8 state, bool bit, __int8 decoded) {
	std::cout <<
		"[---- bit log ----]" << std::endl <<
		"  state : " << std::bitset<2>(state) << std::endl <<
		"  bit : " << std::bitset<1>(bit) << std::endl <<
		"  decoded : " << std::bitset<1>(decoded) << std::endl <<
		"[----         ----]" << std::endl;
}

encoder :: ~encoder() {
	/* destroy object */
	std::cout <<
		"encoder disable"
		<< std::endl;
}