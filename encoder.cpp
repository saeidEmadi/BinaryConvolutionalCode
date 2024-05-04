#include "encoder.h"
#include <iostream>

encoder :: encoder() {
	/* create new object and initial values : 
		- state = 00
	*/
	std::cout <<
		"encoder enable"
		<< std::endl;
	state = 0;
}

encoder :: ~encoder() {
	/* destroy object */
	std::cout <<
		"encoder disable"
		<< std::endl;
}