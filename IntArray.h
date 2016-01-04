#pragma once
#include <stdlib.h>


class IntArray {

public:
	IntArray(int initSize); // constructor
	~IntArray(); // desctructor
	IntArray (const IntArray& arr); // copy constructor
	IntArray(IntArray&& arr); // move constructor

	int getLength(); // number of elements stored in the array
	int getSize(); // returns possible amount of stored int values
	int operator[](int index);
	
	IntArray& operator=(const IntArray& arr); // assignment operator
	IntArray& operator=(IntArray&& arr); // move assingment operator

	void append(int value); // append values at the end of an array
	void erase(int index); // removes value at index of array

private:
	int length; // amount of stored values in the array
	int size; // real size of the array
	int *data; // pointer to int array
	
};
