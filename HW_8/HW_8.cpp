#include <iostream>
#include "LoopFunctions.h"
#include "RecursionFunctions.h"

int main()
{
	// Step 1: Positive & negative
	std::cout << "Step 1: Positive & negative\n";
	int numSteps = 0;
	std::cout << "Enter the number of numbers to enter: ";
	std::cin >> numSteps;
	posNegZero(numSteps);

	std::cout << std::endl;

	// Step 2: Factorial

	// Factorial by Loop
	std::cout << "Step 2: Factorial by Loop\n";
	int numFactorial = 0;
	int result = 0;
	std::cout << "Enter the number of Factorial (Loop): ";
	std::cin >> numFactorial;
	result = factorial(numFactorial);
	std::cout << "LOOP - Factorial number " << numFactorial << " is: " << result << std::endl;

	std::cout << std::endl;

	// Factorial by Recursion
	std::cout << "Step 2: Factorial by Recursion\n";
	int numFactorialRecurs = 0;
	int resultRecurs = 0;
	std::cout << "Enter the number of Factorial (Recursion): ";
	std::cin >> numFactorialRecurs;
	resultRecurs = factorialRecurs(numFactorialRecurs);
	std::cout << "RECURSION - Factorial number " << numFactorialRecurs << " is: " << resultRecurs << std::endl;

	std::cout << std::endl;

	// Step 3: Natural numbers
	std::cout << "Step 3: Natural numbers - Descending and Ascending (Loops and Recursion)\n";
	// 3.1 Descending
	int numDescending = 0;
	std::cout << "Enter the number (Descending): ";
	std::cin >> numDescending;
	printNaturalNumbersDescending(numDescending);

	std::cout << std::endl;

	// 3.2 Ascending
	int numAscending = 0;
	std::cout << "Enter the number (Ascending): ";
	std::cin >> numAscending;
	printNaturalNumbersAscending(numAscending);

	std::cout << std::endl;

	// 3.3 Descending Recursion
	int numDescendingRec = 0;
	std::cout << "Enter the number (Descending Recursion): ";
	std::cin >> numDescendingRec;
	printNaturalNumbersDescendingRecursion(numDescendingRec);

	std::cout << std::endl << std::endl;

	// 3.4 Ascending Recursion
	int numAscendingRec = 0;
	std::cout << "Enter the number (Ascending Recursion): ";
	std::cin >> numAscendingRec;
	printNaturalNumbersAscendingRecursion(numAscendingRec);

	std::cout << std::endl;

    return 0;
}