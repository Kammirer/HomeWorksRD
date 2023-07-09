// Functions with loops
#include <iostream>

void posNegZero(int num) {
	int inputNum = 0;
	int positive = 0;
	int negative = 0;
	int zeroes = 0;

	for (unsigned int i = num; i > 0; i--) {
		std::cout << "Enter your number: ";
		std::cin >> inputNum;
		if (inputNum > 0) {
			positive++;
		}
		else if (inputNum < 0) {
			negative++;
		}
		else {
			zeroes++;
		}
	}
	std::cout << "Positive: " << positive << ", negative: " << negative << ", zeroes: " << zeroes << std::endl;
}

int factorial(int count) {
	int result = 1;
	for (unsigned int i = 1; i <= count; i++) {
		result *= i;
	}
	return result;
}

void printNaturalNumbersDescending(int count) {
	for (unsigned int i = count; i > 0; i--) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void printNaturalNumbersAscending(int count) {
	for (unsigned int i = 1; i <= count; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}