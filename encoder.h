#pragma once
/* Binary Convolutional Codes Encoder */
class encoder{
	public : 
		/*
			Description: Binary Convolutional Codes Encoder Constructor.
			Parameters:
				- void
			Returns:
				- void
		*/
		encoder();
		/*
			Description: encode one bit of message and return encoded .
			Parameters:
				- bool (1: True, 0: False) input bit
			Returns:
				- __int8 encoded message
		*/
		__int8 encode(bool bit);
		~encoder();					// class destructor

	private : 
		/*
			private var __int8 state:2
			2 bit use for show state
		*/
		__int8 state : 2;
		/*
			private func logLevel()
			define print patter for print
			Machine state, input Bit
			encoded bit and nextState
		*/
		void logLevel(__int8 state, bool bit, __int8 decoded, __int8 nextState);
};