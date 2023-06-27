#include <iostream>

int main() 
{
    // STEP 1: Time on time
    std::cout << "=== STEP 1: Time" << std::endl;
    int startSeconds = 0;

    std::cout << "Enter seconds: ";
    std::cin >> startSeconds;

    int hour = 0;
    int minute = 0;
    int second = 0;

    hour = startSeconds / 3600;
    minute = startSeconds % 3600 / 60;
    second = startSeconds % 3600 % 60;

    std::cout << hour << " hour, " << minute << " minutes, " << second << " seconds." << std::endl;
    std::cout << std::endl;

    // STEP 2: Arithmetic operations
    std::cout << "=== STEP 2: Arithmetic operations" << std::endl;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    std::cout << "Enter your three integer numbers: ";
    std::cin >> num1 >> num2 >> num3;

    std::cout << "Sum.: " << num1 + num2 + num3 << std::endl;
    std::cout << "Multip.: " << num1 * num2 * num3 << std::endl;
    std::cout << "Arithmetic mean: " << (num1 + num2 + num3) / 3 << std::endl;
    std::cout << "Comparison num1 >= num2: " << (num1 >= num2) << std::endl;
    std::cout << "Comparison num2 < nu3: " << (num2 < num3) << std::endl;
    std::cout << std::endl;

    // STEP 3: Comparison in BOOL
    std::cout << "=== STEP 3: Comparison in BOOL" << std::endl;
    int number1 = 0;
    int number2 = 0;
    bool lessThan, equal, moreThan, lessOrEqual;

    std::cout << "Enter your two integer numbers: ";
    std::cin >> number1 >> number2;

    lessThan = number1 < number2;
    equal = number1 == number2;
    moreThan = number1 > number2;
    lessOrEqual = number1 <= number2;

    std::cout << "lessThan: " << std::boolalpha << lessThan << std::endl;
    std::cout << "equal: " << std::boolalpha << equal << std::endl;
    std::cout << "moreThan: " << std::boolalpha << moreThan << std::endl;
    std::cout << "lessOrEqual: " << std::boolalpha << lessOrEqual << std::endl;
    std::cout << std::endl;

    // STEP 4: Rectangle
    std::cout << "=== STEP 4: Rectangle" << std::endl;
    double width = 0;
    double height = 0;

    std::cout << "Enter width & height Rectangle: ";
    std::cin >> width >> height;

    double areaRectangle = width * height;
    double perimeterRectangle = width*2 + height*2;

    std::cout << "Area rectangle: " << areaRectangle << std::endl;
    std::cout << "Perimeter rectangle: " << perimeterRectangle << std::endl;
    std::cout << std::endl;

    // STEP 5: Circle
    std::cout << "=== STEP 5: Circle" << std::endl;
    double radiusCircle = 0;
    std::cout << "Enter radius Circle: ";
    std::cin >> radiusCircle;

    double areaCircle = 0;
    double lengthCircle = 0;

    areaCircle = 3.14 * (radiusCircle * radiusCircle);
    lengthCircle = 2 * 3.14 * radiusCircle;

    std::cout << "Area circle: " << areaCircle << std::endl;
    std::cout << "Length circle: " << lengthCircle << std::endl;
    std::cout << std::endl;

    return 0;
}
