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
			private var __int8 state:2
			2 bit use for show state
		*/
		__int8 state : 2;
		/*
			private func logLevel()
			define print pattern for print
			Machine state, input 2 bit
			decoded 2bit and nextState
		*/
		void logLevel(__int8 state, __int8 recv, __int8 encoded, __int8 nextState);
};