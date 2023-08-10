#include "DynamicIntArray.h"
#include <string>

//Implementations go here

//default c-tor
DynamicIntArray::DynamicIntArray() {
    sizeDyn = 0;
    arrayDyn = nullptr;
}

//c-tor with size
DynamicIntArray::DynamicIntArray(std::size_t size) {
    sizeDyn = size;
    arrayDyn = new int[size];
}

//copy c-tor
DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) {
    sizeDyn = other.sizeDyn;
    arrayDyn = new int[other.sizeDyn];
    std::memcpy(arrayDyn, other.arrayDyn, sizeDyn * sizeof(int));
}

//free allocated memory (d-tor)
DynamicIntArray::~DynamicIntArray() {
    delete[] arrayDyn;
}

// operator= (delete memory array, assign. size, new memory to our array with new size, copy data)
DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {
    delete[] arrayDyn;
    sizeDyn = other.sizeDyn;
    arrayDyn = new int[sizeDyn];
    std::memcpy(arrayDyn, other.arrayDyn, sizeDyn * sizeof(int));
    return *this;
}

// operator[] (return element by index)
int& DynamicIntArray::operator[](std::size_t index) {
    return arrayDyn[index];
}

// new Size by array (check sizes, new memory, copy data, delete & assign.)
void DynamicIntArray::setSize(std::size_t newSize) {
    if (newSize > sizeDyn) {
        int* newArray = new int[newSize];
        std::memcpy(newArray, arrayDyn, newSize * sizeof(int));
        delete[] arrayDyn;
        sizeDyn = newSize;
        arrayDyn = newArray;
    }
}

// get size
std::size_t DynamicIntArray::getSize() const {
    return sizeDyn;
}

// clear memory & reset data
void DynamicIntArray::clear() {
    delete[] arrayDyn;
    sizeDyn = 0;
    arrayDyn = nullptr;
}

// add element to end array (new memory with size+1, copy data, add element to end, delete memory & assign.)
void DynamicIntArray::push_back(int element) {
    int* newArray = new int[sizeDyn + 1];
    std::memcpy(newArray, arrayDyn, sizeDyn * sizeof(int));
    newArray[sizeDyn] = element;
    delete[] arrayDyn;
    sizeDyn++;
    arrayDyn = newArray;
}