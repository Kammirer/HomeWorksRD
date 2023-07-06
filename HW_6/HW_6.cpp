#include <iostream>
#include <cctype>

int main()
{
    // STEP 1
    std::cout << "STEP 1: Arithmetic progression\n";
    
    int elemFirst = 0;
    int step = 0;
    int end = 0;

    std::cout << "Enter first elem, step & end number: ";
    std::cin >> elemFirst >> step >> end;

    int num = elemFirst;
    for (unsigned int i = 0; i < end; i++) {
        std::cout << num << " ";
        num += step;
    }
    std::cout << std::endl;

    // STEP 2
    std::cout << "\nSTEP 2: Fibonacci\n";

    int seqFib = 0;

    std::cout << "Enter Fibonacci sequence: ";
    std::cin >> seqFib;

    int prev = 0;
    int curr = 1;
    for (unsigned int i = 0; i < seqFib; i++) {
        if (i == 0) {
            std::cout << curr << " ";
        }
        else {
            curr += prev;
            prev = curr - prev;
            std::cout << curr << " ";
        }
    }
    std::cout << std::endl;

    // STEP 3
    std::cout << "\nSTEP 3: Factorial\n";

    int numFactorial = 0;
    std::cout << "Enter the number of Factorial: ";
    std::cin >> numFactorial;

    int result = 1;
    for (unsigned int i = 1; i <= numFactorial; i++) {
        result *= i;
    }
    std::cout << "Factorial number " << numFactorial << " is: " << result << std::endl;

    // STEP 4
    std::cout << "\nSTEP 4: Figures\n";

    std::cout << "Figure A\n";
    int rowsA = 0;
    std::cout << "Enter the number of rows (triangle A): ";
    std::cin >> rowsA;
    for (unsigned int i = rowsA; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Figure B\n";
    int rowsB = 0;
    std::cout << "Enter the number of rows (triangle B): ";
    std::cin >> rowsB;
    
    for (unsigned int i = 0; i < rowsB; i++) {
        for (unsigned int j = 0; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Figure C\n";
    int rowsC = 0;
    int colC = 0;
    std::cout << "Enter number of rows & coll.: ";
    std::cin >> rowsC >> colC;

    for (unsigned int i = 0; i < rowsC; i++){
        for (unsigned int j = 0; j < colC; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Figure D\n";
    int rowsD = 0;
    std::cout << "Enter the number of rows : ";
    std::cin >> rowsD;

    for (unsigned int i = 0; i < rowsD; i++) {
        for (unsigned int j = 0; j < i; j++) {
            std::cout << " ";
        }
        for (unsigned int k = 0; k < rowsD; k++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Figure E\n";
    int rowsE = 0;
    std::cout << "Enter the number of rows: ";
    std::cin >> rowsE;

    for (unsigned int i = 0; i < rowsE; i++) {
        for (unsigned int j = 0; j <= i; j++) {
            std::cout << ((i+j) % 2);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // STEP 5
    std::cout << "STEP 5: Char\n";

    char inChar;
    int sumChar = 0;

    while (true) {
        std::cout << "Enter a char:";
        std::cin >> inChar;

        if (inChar >= 'a' && inChar <= 'z') {
            inChar = toupper(inChar);
            std::cout << "To upper: " << inChar << std::endl;
        }
        else if (inChar >= '0' && inChar <= '9') {
            int numChar = inChar - '0';
            sumChar += numChar;
            std::cout << "Sum char: " << sumChar << std::endl;
        }
        else if (inChar == '.') {
            std::cout << "End programm!" << std::endl;
            break;
        }
        else {
            std::cout << "This character is not processed by the program..." << std::endl;
        }
    }

    return 0;
}