#include <iostream>

void swap(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool calculateSum(const double* arr, int arrSize, double& sum) {
    if (arrSize == 0) {
        return false;
    }

    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];
    }
    return true;
}

bool find(const int* arr, int size, int elem) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == elem) {
            return true;
        }
    }
    return false;
}

int main()
{
    // Step 1
    std::cout << "Step 1: swap(&) and swap(*)" << std::endl;

    int numA = 0;
    int numB = 0;
    std::cout << "Enter your 2 nums: ";
    std::cin >> numA >> numB;
    swap(numA, numB);
    std::cout << "numA: " << numA << " numB: " << numB << std::endl << std::endl;

    int numA_ptr = 0;
    int numB_ptr = 0;
    std::cout << "Enter your 2 nums (ptr): ";
    std::cin >> numA_ptr >> numB_ptr;
    swap(&numA_ptr, &numB_ptr);
    std::cout << "numA_ptr: " << numA_ptr << " numB_ptr: " << numB_ptr << std::endl << std::endl;

    // Step 2
    std::cout << "Step 2: calculate Sum" << std::endl;
    double array[] = {1.2, 5.1, 0.4, 1.0, 2.2};
    int arrSize = sizeof(array) / sizeof(double);
    double sum = 0;
    
    bool arrAmount = calculateSum(array, arrSize, sum);
    
    if (arrAmount) {
        std::cout << "Sum array: " << sum << std::endl << std::endl;
    }
    else {
        std::cout << "Array is invalid!" << std::endl << std::endl;
    }

    // Step 3
    std::cout << "Step 2: find" << std::endl;
    int arrFind[] = {0, 4, 1, 5, 2, 7, 11 ,8};
    int size = sizeof(arrFind) / sizeof(int);
    int enterNum = 0;

    std::cout << "Enter your integer number: ";
    std::cin >> enterNum;

    bool resFind = find(arrFind, size, enterNum);
    std::cout << "Your number has been found: " << std::boolalpha << resFind << std::endl;

    return 0;
}