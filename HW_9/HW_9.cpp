#include <iostream>
#include "FuncsHW9.h"

int main()
{
    // Step 1
    std::cout << "Step 1: translateArray" << std::endl;

    const int size = 10;
    int numArray[size] = {};

    for (int i = 0; i < size; i++) {
        std::cout << "Enter number for Array: ";
        std::cin >> numArray[i];
    }

    translateArray(numArray, size);

    std::cout << "New numbers Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << numArray[i] << " ";
    }

    std::cout << std::endl << std::endl;

    // Step 2
    std::cout << "Step 2: toUppercase" << std::endl;

    const int lenght = 100;
    char str[lenght];

    std::cout << "Enter your string: ";
    std::cin.get();
    std::cin.getline(str, lenght);

    toUppercase(str);
    std::cout << "Your toUpper string: " << str << std::endl;

    std::cout << std::endl;

    // Step 3
    std::cout << "Step 3: isPalindrom" << std::endl;

    const int lenghtPalindrom = 100;
    char strPalindrom[lenghtPalindrom];
    bool boolPal;

    std::cout << "Enter your string Palindrom: ";
    std::cin.getline(strPalindrom, lenghtPalindrom);

    boolPal = isPalindrom(strPalindrom);
    std::cout << "Palindrom: " << std::boolalpha << boolPal << std::endl;

    std::cout << std::endl;

    // Step 4
    std::cout << "Step 4: parseStringLetters" << std::endl;

    const int lenghtLetters= 100;
    char strLetters[lenghtLetters];
    int vowelsCount = 0;
    int constonantsCount = 0;

    std::cout << "Enter your string letters: ";
    std::cin.getline(strLetters, lenghtLetters);

    parseStringLetters(strLetters, vowelsCount, constonantsCount);

    std::cout << "Number of vowels: " << vowelsCount << std::endl;
    std::cout << "Number of consonants: " << constonantsCount << std::endl;

    std::cout << std::endl;

    // Step 5
    std::cout << "Step 5: isEqual str" << std::endl;

    const int lenghtStr = 100;
    char firstStr[lenghtStr] = {};
    char secondStr[lenghtStr] = {};
    bool resStr;

    std::cout << "Enter your first string: ";
    std::cin.getline(firstStr, lenghtStr);
    std::cout << "Enter your second string: ";
    std::cin.getline(secondStr, lenghtStr);

    resStr = isEqual(firstStr, secondStr);

    std::cout << "First string == Second string: " << std::boolalpha << resStr << std::endl;

    return 0;
}