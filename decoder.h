#pragma once
#include "node.h"
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
				- unsigned __int8 received bit
			Returns:
				- unsigned __int8 decoded message
		*/
		unsigned __int8 decode(unsigned __int8 recv);
		~decoder();					// class destructor

	private:
		/*
			Description: graph Tracer.
			Trace routes of graph
			Parameters:
				- unsigned __int8 state
				- unsigned __int8 data
				- unsigned __int8 level
			Returns:
				- node * | node pointer
		*/
		node * graphTracer(unsigned __int8 state, unsigned __int8 data, unsigned __int8 level);
		/*
			Description: print decoded Path.
			Parameters:
				- node pointerl
			Returns:
				- void
		*/
		void decodeZero(node* n);
		/*
			Description: find min graph distances.
			used this function to refine and remove large distances 
			Parameters:
				- unsigned __int8 state
				- unsigned __int8 data
				- unsigned __int8 level
			Returns:
				- node * | node pointer
		*/
		node* getMinDistancePaths(unsigned __int8 state, unsigned __int8 data, unsigned __int8 level);
		/*
			Description: find min graph distances
			and print state and value for error-correction
			Parameters:
				- node *n | node pointer
			Returns:
				- __int8 distance value
		*/
		__int8 printStatesMinPath(node* n);
		/*
			private func logLevel()
			define print pattern for print
		*/
		void logLevel();
		/*
			calculate the Hamming distance between two integers
			Parameters:
				- unsigned __int8 x
				- unsigned __int8 y
			Returns:
				- unsigned __int8 distance
		*/
		unsigned __int8 hammingDistance(unsigned __int8 x, unsigned __int8 y);
};