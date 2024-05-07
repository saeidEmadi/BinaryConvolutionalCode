#pragma once
#ifndef NODE_H
#define NODE_H

class node{
	public :
		/*
			Description: node (Path) Constructor.
			Parameters:
				- unsigned __int8 state
				- node NextFirstStateNode
				- node NextScondStateNode
				- unsigned __int8 distance
			Returns:
				- void
		*/
		node(unsigned __int8 state);
		/*
			Description: set node state
			Parameters:
				- unsigned __int8 state value
			Returns:
				- bool : return assert value
		*/
		bool setState(unsigned __int8 state);
		/*
			Description: get node state
			Parameters:
				- void
			Returns:
				- const unsigned __int8 : return state value
		*/
		unsigned __int8 const getState();
		/*
			Description: set Next First State Node
			Parameters:
				- node nextNode pointer
			Returns:
				- bool : return assert value
		*/
		bool setNextFirstStateNode(node &nextNode);
		/*
			Description: get Next First State Node
			Parameters:
				- void
			Returns:
				- node NextFirstStateNode pointer
		*/
		node * getNextFirstStateNode();
		/*
			Description: set Next Scond State Node
			Parameters:
				- node nextNode pointer
			Returns:
				- bool : return assert value
		*/
		bool setNextScondStateNode(node &nextNode);
		/*
			Description: get Next Scond State Node
			Parameters:
				- void
			Returns:
				- node NextScondStateNode pointer
		*/
		node* getNextScondStateNode();
		/*
			Description: set Next First State Node Distance value
						 between edge and bit
			Parameters:
				- unsigned __int8 distance value
			Returns:
				- bool : return assert value
		*/
		bool setNextFirstStateNodeDistance(unsigned __int8 distance);
		/*
			Description: set Next Scond State Node Distance value
						 between edge and bit
			Parameters:
				- unsigned __int8 distance value
			Returns:
				- bool : return assert value
		*/
		bool setNextScondStateNodeDistance(unsigned __int8 distance);
		/*
			Description: get Next First State Node Distance value
			Parameters:
				- void
			Returns:
				- const unsigned __int8 : return distance value
		*/
		unsigned __int8 const getNextFirstStateNodeDistance();
		/*
			Description: get Next Scond State Node Distance value
			Parameters:
				- void
			Returns:
				- const unsigned __int8 : return distance value
		*/
		unsigned __int8 const getNextScondStateNodeDistance();
	private :
		/*
			2bit unsigned __int8
			node state machine value
			for cal distance
		*/
		unsigned __int8 state : 2;
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
			unsigned __int8 
			Next First State Node Distance
			edge distance value
			between state and bit input
		*/
		unsigned __int8 NextFirstStateNodeDistance;
		/*
			unsigned __int8
			Next Scond State Node Distance
			edge distance value
			between state and bit input
		*/
		unsigned __int8 NextScondStateNodeDistance;

};
#endif