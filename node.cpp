#include "node.h"
#include <cassert>
#include <exception>
#include <iostream>

node::node() {
	/* create new object and initial values */
	this->setState(0);
	this->setDistance(0);
	this->NextFirstStateNode = NULL;
	this->NextScondStateNode = NULL;
}

__int8 const node::getDistance() {
	return this->distance;
}

bool node::setDistance(__int8 distance) {
	try {
		this->distance = distance;
		return true;
	}
	catch (const std::exception&) {
		std::cout << "can't assing distance" << std::endl;
		return false;
	}
	return false;
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

__int8 const node::getState() {
	return this->state;
}

bool node::setState(__int8 state) {
	try{
		this->state = state;
		return true;
	}catch (const std::exception&){
		std::cout << "can't assing state" << std::endl;
		return false;
	}
	return false;
}