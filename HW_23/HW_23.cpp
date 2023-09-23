#include <iostream>
#include "DynamicArray.h"
#include "InplaceArray.h"

int main()
{
	// == Dynamic array
	DynamicArray<int> myIntArray(5);
	DynamicArray<float> myFloatArray(4);

	std::cout << myIntArray.getSize() << "\n";

	myIntArray.push_back(45);
	myIntArray.push_back(13);
	myIntArray.push_back(5);

	myIntArray.pop_back();

	std::cout << myIntArray.back() << "\n";

	myIntArray.reserve(9);

	std::cout << myIntArray.getCapacity() << "\n";

	myIntArray.pop_back();
	std::cout << myIntArray.getSize() << "\n";
	std::cout << myIntArray.back() << "\n";

	std::cout << "\n";

	std::cout << myFloatArray.getSize() << "\n";
	
	myFloatArray.push_back(3);
	myFloatArray.push_back(7);
	myFloatArray.push_back(21);
	myFloatArray.push_back(21);
	myFloatArray.push_back(21);
	myFloatArray.push_back(31);

	myFloatArray.reserve(12);
	
	std::cout << myFloatArray.getCapacity() << "\n";

	myFloatArray.pop_back();
	std::cout << myFloatArray.getSize() << "\n";
	std::cout << myFloatArray.back() << "\n";

	std::cout << "\n";

	// == Inplace array
	InplaceArray<int, 5> myIntInplaceArray;
	
	myIntInplaceArray.push_back(4);
	myIntInplaceArray.push_back(17);

	std::cout << myIntInplaceArray.back() << "\n";

	return 0;
}