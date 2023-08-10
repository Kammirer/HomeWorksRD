#define _CRT_SECURE_NO_WARNINGS

#include <vld.h>
#include <iostream>
#include <cstring>
#include "DynamicIntArray.h"

// Step 2
class StringCustom {
public:
    StringCustom();
    StringCustom& operator=(const char* c_str);
    void assign(const char* c_str);

    ~StringCustom() { delete m_str; }

    std::size_t getLen() const { return strlen(m_str); }
    std::size_t getSize() const { return getLen() + 1; }
private:
    char* m_str;

};

StringCustom::StringCustom()
{
    m_str = new char[1];
    m_str[0] = '\0';
}

StringCustom& StringCustom::operator=(const char* c_str)
{
    delete m_str;

    if (c_str == nullptr)
    {
        m_str = new char;
        *m_str = '\0';
    }
    else
    {
        const std::size_t size = strlen(c_str);
        m_str = new char[size];

        for (int i = 0; i < size; i++)
        {
            m_str[i] = c_str[i];
        }
    }

    return *this;
}

void StringCustom::assign(const char* c_str)
{
    delete m_str;

    m_str = new char[strlen(c_str) + 1];
    strcpy(m_str, c_str);
}


int* allocateArray(int size)
{
    int* arrayInt = new int[size];
    return arrayInt;
}

void clearArray(int* numbers)
{
    delete numbers;
}

int** allocateArrayOfArrays(int rows, int columns)
{
    int** arrayPtr = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        //Size of each individual array in this case may be different
        arrayPtr[i] = new int[columns];
    }

    return arrayPtr;
}

//columns is not needed
//allocated memory size for new[] is stored internally
void clearArrayOfArrays(int** arrayPtr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        //remove each individual array in bigger container one by one
        delete[] arrayPtr[i];
    }
    delete arrayPtr;
}

int main()
{
    // STEP 1
    //Your test cases here
    //Read size and content of an array from cin
    //Process data in any way to test functionality
    //Make sure to test all methods in different variations

    DynamicIntArray array1(5);
    std::cout << "default size: " << array1.getSize() << std::endl;

    array1.push_back(14);
    std::cout << "Element push_back: " << array1.operator[](5) << std::endl;
    std::cout << "New size after push_back: " << array1.getSize() << std::endl;

    DynamicIntArray array2(10);
    array2.push_back(25);

    DynamicIntArray array3 = array2;
    std::cout << "Element index: " << array3.operator[](10) << std::endl;

    array1.setSize(8);
    std::cout << "New size array1 after setSize: " << array1.getSize() << std::endl;

    std::cout << std::endl;

    int sizeArray = 0;
    std::cout << "Enter size array: ";
    std::cin >> sizeArray;

    DynamicIntArray arrayCin;

    for (int i = 0; i < sizeArray; i++) {
        int val;
        std::cout << "Enter elements of array: ";
        std::cin >> val;
        arrayCin.push_back(val);
    }
    std::cout << "Element index: " << arrayCin.operator[](1) << std::endl;
    std::cout << "Size arrayCin: " << arrayCin.getSize() << std::endl;

    arrayCin.clear();
    std::cout << "Size arrayCin after clear method: " << arrayCin.getSize() << std::endl;

    std::cout << std::endl;

    // STEP 2 - memory leaks

    //CASE 1
    StringCustom a;
    a = "Hello";
    a = "There";

    //CASE 2 ??
    StringCustom b;
    b.assign("Hello Here");
    b.assign("Simple hello");

    //CASE 3
    //Suppose it was read dynamically from somewhere
    int ArraySize = 10;
    int* arrayInt = allocateArray(ArraySize);
    clearArray(arrayInt);

    //CASE 4
    int rows = 10;
    int columns = 20;
    int** array = allocateArrayOfArrays(rows, columns);
    clearArrayOfArrays(array, rows);

    return 0;
}