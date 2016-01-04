#include "IntArray.h"
#include <iostream>


int main() {
	IntArray arr = IntArray(4);

	arr.append(3);	
	arr.append(2);	
	arr.append(1);	
	arr.append(5);

	std::cout << "inserted numbers... ";
	for(int i = 0; i < arr.getLength(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "erase number at index 2... ";
	arr.erase(2);
	for(int i = 0; i < arr.getLength(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "print last number...\n";
	std::cout << arr[-1] << std::endl;

	std::cout << "press key to exit" << std::endl;
	getchar();

	return 0;

}
