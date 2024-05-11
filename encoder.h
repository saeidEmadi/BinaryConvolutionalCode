#pragma once
#ifndef ENCODER_H
#define ENCODER_H
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
		__int8 const encode(bool bit);
		/*
			Description: encode one bit of message
				return and print encoded bit detail.
			Parameters:
				- bool (1: True, 0: False) input bit
			Returns:
				- __int8 encoded message
		*/
		__int8 const encodeDetail(bool bit);
		~encoder();					// class destructor

	private : 
		/*
			private var __int8 state:2
			2 bit use for show state
		*/
		__int8 state : 2;
		/*
			Description: encode one bit of message and return encoded .
			Parameters:
				- const bool (1: True, 0: False) input bit pointer
				- const __int8 state pointer
			Returns:
				- __int8 encoded message
		*/
		__int8 encodedMsg(const bool& bit, const __int8& state);
		/*
			get Next State
			Parameters:
				- const bool bit : input bit refrence
				- const __int8 state refrence
			Returns:
				- __int8 state
		*/
		__int8 nextState(const bool& bit, const __int8& state);
		/*
			private func logLevel()
			define print pattern for print
			Machine state, input Bit
			encoded bit and nextState
			Parameters:
				- const __int8 state pointer
				- const bool bit : input bit pointer
				- const __int8 decoded : decoded message pointer
				- const __int8 nextState pointer
		*/
		void logLevel(const __int8& state, const bool& bit,
			const __int8& decoded, const __int8& nextState);
};

#endif