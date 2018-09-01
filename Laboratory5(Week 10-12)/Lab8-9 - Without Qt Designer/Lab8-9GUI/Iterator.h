#pragma once
#include "DynamicVector.h"
#include "Tutorial.h"
#include <vector>
class Iterator {
private:
	std::vector<Tutorial> tutorials;
	int current;
public:
	Iterator();
	/*
		Add an tutorial to the dynamic vector
		Input: t - Tutorial - the given tutorial
	*/
	void add(const Tutorial& t);
	/*
		Returns the current tutorial the iterator is iterating
	*/
	Tutorial getCurrentTutorial();
	/*
		Open the current tutorial the iterator is at
	*/
	void open();
	/*
		Opens the next tutorial from the dynamic array
	*/
	void next();
	/*
		Returns true if the dynamic array is empty
	*/
	bool isEmpty();
	/*
		It empties the iterator
	*/
	void emptyIterator();
};