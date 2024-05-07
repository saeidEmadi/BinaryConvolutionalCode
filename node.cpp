#include "node.h"
#include <cassert>
#include <exception>
#include <iostream>

/* create new object and initial values */

node::node(unsigned __int8 state){
	this->setState(state);
	this->NextFirstStateNode = nullptr;
	this->NextScondStateNode = nullptr;
	this->setNextFirstStateNodeDistance(0);
	this->setNextScondStateNodeDistance(0);
}

bool node::setState(unsigned __int8 state) {
	try {
		this->state = state;
		return true;
	}
	catch (const std::exception&) {
		std::cout << "can't assing state" << std::endl;
		return false;
	}
	return false;
}

unsigned __int8 const node::getState() {
	return this->state;
}
node* node::getNextScondStateNode() {
	return this->NextScondStateNode;
}

bool node::setNextScondStateNode(node& nextNode) {
	try {
		this->NextScondStateNode = &nextNode;
		return true;
	}
	catch (const std::exception&) {
		std::cout << "can't assing NextScondStateNode" << std::endl;
		return false;
	}
	return false;
}

node * node::getNextFirstStateNode() {
	return this->NextFirstStateNode;
}

bool node::setNextFirstStateNode(node &nextNode) {
	try {
		this->NextFirstStateNode = &nextNode;
		return true;
	}catch (const std::exception&) {
		std::cout << "can't assing NextFirstStateNode" << std::endl;
		return false;
	}
	return false;
}

unsigned __int8 const node::getNextFirstStateNodeDistance() {
	return this->NextFirstStateNodeDistance;
}

unsigned __int8 const node::getNextScondStateNodeDistance() {
	return this->NextScondStateNodeDistance;
}

bool node::setNextFirstStateNodeDistance(unsigned __int8 state) {
	try{
		this->NextFirstStateNodeDistance = state;
		return true;
	}catch (const std::exception&){
		std::cout << "can't assing state" << std::endl;
		return false;
	}
	return false;
}

bool node::setNextScondStateNodeDistance(unsigned __int8 state) {
	try {
		this->NextScondStateNodeDistance = state;
		return true;
	}
	catch (const std::exception&) {
		std::cout << "can't assing state" << std::endl;
		return false;
	}
	return false;
}