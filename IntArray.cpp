#include "IntArray.h"
#include <math.h>

IntArray::IntArray(int initSize) {
	size = initSize;
	length = 0;
	data = new int[size];

}

IntArray::~IntArray() {
	delete [] data;
}

IntArray::IntArray(const IntArray& arr) { // copy constructor
	size = arr.size;
	length = arr.length;
	data = new int[size];
	for (int i = 0; i < length; ++i) {
		data[i] = arr.data[i];
	}
	
}

IntArray::IntArray(IntArray&& arr) { // move constructor
	data = arr.data;	
	size = arr.size;
	length = arr.length;
	arr.data = nullptr;
}

// get amount of stored values
int IntArray::getLength(){
	return length;
}

// not used yet
int IntArray::getSize(){
	return size;
}

int IntArray::operator[](int index) {
	
	// index out of bounds
	if(abs(index) >= length) {
		return NULL;
	}
	// starting from last element
	if (index < 0) {
		return data[length + index];

	}
	// positive value: just return value at position index	
	return data[index];
}

// assignment operator
IntArray& IntArray::operator=(const IntArray& arr) {
	if (&arr == this) {
		return *this;
	}
	
	delete [] data;
	size = arr.size;
	data = new int[size];
	length = arr.length;
	for(int i = 0; i < length; ++i) {
		data[i] = arr.data[i];
	}
	return *this;
}

// move assignment operator
IntArray& IntArray::operator=(IntArray&& arr) {
	if (&arr == this) {
		return *this;
	}
	delete [] data;
	data = arr.data;
	arr.data = nullptr;

}

void IntArray::append(int value) {
	// if there is space in the current array
	// just store the new value and increase the length
	// which is also the new index for the next value 
	// to store in the array
	if (size > length) {
		data[length++] = value;
	}
	// if not, double the size of the array
	else {
		// make a pointer to the current array
		int *tmp = data;
		size = 2 * size;
		// allocate new memory for a larger array
		data = new int[size];
		// store the old values in the new array
		for(int i = 0; i < length; ++i) {
			data[i] = tmp[i];
		}
		// store the new value
		data[length++] = value;
		// free memory of old array
		delete [] tmp;
	}

}

// delete an element, not working with negative indices
void IntArray::erase(int index) {
	// start at index
	// shift every value one position back
	for (int i = index; i < length - 1; ++i) {
		data[i] = data[i+1];
	}
	// decrease amount of stored values
	length--;
}

















