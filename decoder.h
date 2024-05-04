#pragma once
/* Binary Convolutional Codes Decoder */
class decoder {
	public:
		/*
			Description: Binary Convolutional Codes Decoder Constructor.
			Parameters:
				- void
			Returns:
				- void
		*/
		decoder();
		/*
			Description: encode one bit of message and return encoded .
			Parameters:
				- __int8 received bit
			Returns:
				- __int8 decoded message
		*/
		__int8 decode(__int8 recv);
		~decoder();					// class destructor

	private:
		/*
			private func logLevel()
			define print pattern for print
			Machine state, input 2 bit
			decoded 2bit and nextState
		*/
		void logLevel(__int8 state, __int8 recv, __int8 encoded, __int8 nextState);
		/*
			calculate the Hamming distance between two integers
			Parameters:
				- __int8 x
				- __int8 y
			Returns:
				- __int8 distance
		*/
		__int8 hammingDistance(__int8 x, __int8 y);
		/*
			calculate the distance for error correction
			use DFS idea (recursive)
			Parameters:
				- int level
				- __int8 state
				- __int8 bit
			Returns:
				- __int8 distance
		*/
		__int8 distanceCal(int level, __int8 state, __int8 bit);
};