#include <iostream>

const int COLUMN = 3;

enum class SortingDirection {byRows, byColumn};

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

void printArr(int arr[][COLUMN], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < COLUMN; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void bubleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        bool sortMark = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                sortMark = true;
            }
        }
        if (!sortMark) {
            break;
        }
    }
}

void quickSort(int arr[][COLUMN], int left, int right, SortingDirection direction) {
    if (left >= right) {
        return;
    }

    int pivot;

    if (direction == SortingDirection::byRows) {
        pivot = arr[(left + right) / 2][0];
    }
    else {
        pivot = arr[0][(left + right) / 2];
    }

    int i = left;
    int j = right;

    while (i <= j) {
        if (direction == SortingDirection::byRows) {
            while (arr[i][0] < pivot) {
                i++;
            }
            while (arr[j][0] > pivot) {
                j--;
            }
        }
        else {
            while (arr[0][i] < pivot) {
                i++;
            }
            while (arr[0][j] > pivot) {
                j--;
            }
        }

        if (i <= j) {
            if (direction == SortingDirection::byRows) {
                for (int k = 0; k < COLUMN; k++) {
                    std::swap(arr[i][k], arr[j][k]);
                }
            }
            else {
                for (int k = 0; k < (right + 1); k++) {
                    std::swap(arr[k][i], arr[k][j]);
                }
            }
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j, direction);
    }
    if (i < right) {
        quickSort(arr, i, right, direction);
    }
}

void sort(int arr[][COLUMN], int row, SortingDirection direction) {
    if (direction == SortingDirection::byRows) {
        quickSort(arr, 0, row - 1, SortingDirection::byRows);
    }
    else {
        quickSort(arr, 0, COLUMN - 1, SortingDirection::byColumn);
    }
}

int main()
{
    // Step 1
    std::cout << "Step 1: buble sort" << std::endl;
    const int sizeBuble = 6;
    int arrBuble[sizeBuble] = { 9, 4, 14, 6, 3, 1 };

    std::cout << "Array before buble sort: ";
    printArr(arrBuble, sizeBuble);

    std::cout << std::endl;
    bubleSort(arrBuble, sizeBuble);

    std::cout << "Array after buble sort: ";
    printArr(arrBuble, sizeBuble);

    std::cout << std::endl << std::endl;

    // Step 2
    std::cout << "Step 2: quick sort" << std::endl;
    const int sizeRow = 3;
    int arrQuickSort[sizeRow][COLUMN] = { { 6, 3, 1 },
                                          { 5, 0, 2 },
                                          { 8, 4, 7 } };

    std::cout << "Original 2D array:" << std::endl;
    printArr(arrQuickSort, sizeRow);
    std::cout << std::endl;
    
    sort(arrQuickSort, sizeRow, SortingDirection::byRows);

    std::cout << "2D array after sort by rows:" << std::endl;
    printArr(arrQuickSort, sizeRow);
    std::cout << std::endl;
    
    sort(arrQuickSort, sizeRow, SortingDirection::byColumn);

    std::cout << "2D array after sort by columns:" << std::endl;
    printArr(arrQuickSort, sizeRow);
    std::cout << std::endl;

    // Step 3
    std::cout << "Step 3: time/space complexity by big-O\n\n";
    
    std::cout << "3.1. github.com/robot-dreams-code/UA_C_PLUS_PLUS-FOR-GAME-DEVELOPMENT-01/blob/main/Lecture12/HW3_Code/HW3_Code.cpp:\n";
    std::cout << "= time complexity: O(ROWS * log COLUMNS)\n";
    std::cout << "= space complexity: O(1)\n";

    std::cout << std::endl;

    std::cout << "3.2. github.com/robot-dreams-code/UA_C_PLUS_PLUS-FOR-GAME-DEVELOPMENT-01/blob/main/Lecture12/HW12_3_2/HW12_3_2.cpp:\n";
    std::cout << "= time complexity: O(size^2)\n";
    std::cout << "= space complexity: O(1)\n";
    return 0;
}