#pragma once
#ifndef NODE_H
#define NODE_H

class node{
	public :
		/*
			Description: node (Path) Constructor.
			Parameters:
				- void
			Returns:
				- void
		*/
		node();
		/*
			Description: set node state
			Parameters:
				- __int8 state value
			Returns:
				- bool : return assert value
		*/
		bool setState(__int8 state);
		/*
			Description: get node state
			Parameters:
				- void
			Returns:
				- const __int8 : return state value
		*/
		__int8 const getState();
		/*
			Description: set Next First State Node
			Parameters:
				- node nextNode
			Returns:
				- bool : return assert value
		*/
		bool setNextFirstStateNode(node nextNode);
		/*
			Description: get Next First State Node
			Parameters:
				- void
			Returns:
				- const node NextFirstStateNode
		*/
		node const getNextFirstStateNode();
		/*
			Description: set Next Scond State Node
			Parameters:
				- node nextNode
			Returns:
				- bool : return assert value
		*/
		bool setNextScondStateNode(node nextNode);
		/*
			Description: get Next Scond State Node
			Parameters:
				- void
			Returns:
				- const node NextScondStateNode
		*/
		node const getNextScondStateNode();
		/*
			Description: set Distance value
						 between edge and bit
			Parameters:
				- __int8 distance value
			Returns:
				- bool : return assert value
		*/
		bool setDistance(__int8 distance);
		/*
			Description: get Distance value
			Parameters:
				- void
			Returns:
				- const __int8 : return distance value
		*/
		__int8 const getDistance();
		~node();					// class destructor
	private :
		/*
			2bit __int8
			node state machine value
			for cal distance
		*/
		__int8 state : 2;
		/*
			node NextFirstStateNode value
			for route first next node
		*/
		node * NextFirstStateNode;
		/*
			node NextScondStateNode value
			for route second next node
		*/
		node * NextScondStateNode;
		/*
			__int8 distance
			edge distance value
			between state and bit input
		*/
		__int8 distance;

};
#endif