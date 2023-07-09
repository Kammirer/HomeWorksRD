// Functions with Recursion
#include <iostream>

int factorialRecurs(int count) {
	if (count == 0) {
		return 1;
	}
	else {
		return count * factorialRecurs(count - 1);
	}
}

void printNaturalNumbersDescendingRecursion(int count) {
	if (count > 0) {
		std::cout << count << " ";
		printNaturalNumbersDescendingRecursion(count - 1);
	}
}

void printNaturalNumbersAscendingRecursion(int count) {
	if (count > 0) {
		printNaturalNumbersAscendingRecursion(count - 1);
		std::cout << count << " ";
	}
}