#include <iostream>

bool linerSearch(int arr[][4], int rows, int coll, int num) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < coll; j++) {
            if (arr[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

enum class SortingDirection {
    ascending,
    descending
};

bool isSorted(const int* arr, int size, SortingDirection direction) {
    if (direction == SortingDirection::ascending) {
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[i -1]) {
                return false;
            }
        }
    }
    else if (direction == SortingDirection::descending) {
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[i -1]) {
                return false;
            }
        }
    }
    return true;
}

void printArray1(int arr[][5], int rows, int coll) {
    for (int j = coll-1; j >= 0; j--) {
        for (int i = 0; i < rows; i++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printArray2(int arr[][5], int rows, int coll) {
    for (int i = rows - 1; i >= 0; i--) {
        if (i % 2 == 0) { // если строка четная <-
            for (int j = coll - 1; j >= 0; j--) {
                std::cout << arr[i][j] << " ";
            }
        }
        else { // если строка не четная строка ->
            for (int j = 0; j < coll; j++) {
                std::cout << arr[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    // Step 1
    std::cout << "Step 1: Liner Search." << std::endl;
    const int rows = 3;
    const int coll = 4;
    int numSearch = 0;

    int arrSearhc[rows][coll] = { {10, 5, 6, -8}, {-4, 11, 2, 9}, {0, -1, 3, 12} };

    std::cout << "Enter your integer num to search in liner array: ";
    std::cin >> numSearch;

    bool resultSearch = linerSearch(arrSearhc, rows, coll, numSearch);
    std::cout << "Search sucsess: " << std::boolalpha << resultSearch << std::endl << std::endl;

    //Step 2
    std::cout << "Step 2: Sorting Direction" << std::endl;
    const int sizeSort = 7;
    int arrSort[sizeSort] = {15, 13, 10, 8, 7, 4, 1};
    
    bool resAscending = isSorted(arrSort, sizeSort, SortingDirection::ascending);
    bool resDescending = isSorted(arrSort, sizeSort, SortingDirection::descending);

    std::cout << "Ascending: " << std::boolalpha << resAscending << std::endl;
    std::cout << "Descending: " << std::boolalpha << resDescending << std::endl << std::endl;

    //Step 3
    std::cout << "Step 3: ptint array" << std::endl;
    const int rowSize = 4;
    const int collSize = 5;

    int arrOut[rowSize][collSize] = { { 1,  2,  3,  4,  5  },
                                      { 6,  7,  8,  9,  10 }, 
                                      { 11, 12, 13, 14, 15 },
                                      { 16, 17, 18, 19, 20 } };
    
    std::cout << "First print:" << std::endl;
    printArray1(arrOut, rowSize, collSize);
    
    std::cout << std::endl << "Second print:" << std::endl;
    printArray2(arrOut, rowSize, collSize);

    return 0;
}