#include <iostream>
#include <iomanip>

enum class WeekDay : int
{
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

int main()
{
    // 1 STEP: cin/cout numbers
    std::cout << "=== 1 STEP: cin/cout numbers ===" << std::endl;
    int var1 = 0;
    int var2 = 0;
    
    std::cout << "Enter two numbers separated by a space: ";
    std::cin >> var1 >> var2;

    int var3 = var2;
    var2 = var1;
    var1 = var3;

    std::cout << "First number: " << var1 << " and Second number: " << var2 << std::endl;
    std::cout << std::endl;

    // 2 STEP: double_1
    std::cout << "=== 2 STEP: double_1 ===" << std::endl;
    double myDouble = 23.029080234820;
    
    std::cout << "Double: " << myDouble << std::endl;
    std::cout << "Double by Int: " << int(myDouble) << std::endl;
    std::cout << std::setw(50) << std::right << std::setfill('$') << std::setprecision(20) << myDouble << std::endl;
    std::cout << std::endl;

    // 3 STEP: double_2
    std::cout << "=== 3 STEP: double_2 ===" << std::endl;
    double myDoubleVar = 567.8374513;

    std::cout << "Two signs: " << std::setprecision(5) << myDoubleVar << std::endl;
    std::cout << "Four signs: " << std::setprecision(7) << myDoubleVar << std::endl;
    std::cout << "Six signs: " << std::setprecision(9) << myDoubleVar << std::endl;
    std::cout << "Standard notation: 5.678374513*10^2" << std::endl;
    std::cout << "E-notation: 5.678374513e2" << std::endl;
    std::cout << std::endl;

    // 4 STEP: days of the week
    std::cout << "=== 4 STEP: days of the week ===" << std::endl;
    std::cout << "Monday: " << int(WeekDay::Monday) << std::endl;
    std::cout << "Tuesday: " << int(WeekDay::Tuesday) << std::endl;
    std::cout << "Wednesday: " << int(WeekDay::Wednesday) << std::endl;
    std::cout << "Thursday: " << int(WeekDay::Thursday) << std::endl;
    std::cout << "Friday: " << int(WeekDay::Friday) << std::endl;
    std::cout << "Saturday: " << int(WeekDay::Saturday) << std::endl;
    std::cout << "Sunday: " << int(WeekDay::Sunday) << std::endl;
    std::cout << std::endl;

    // 5 STEP: Bool
    std::cout << "=== 5 STEP: Bool ===" << std::endl;
    bool myBool = true;
    std::cout << "Enter your number: ";
    std::cin >> myBool;

    std::cout << "Noboolalpha: " << std::noboolalpha << myBool << std::endl;
    std::cout << "Boolalpha: " << std::boolalpha << myBool << std::endl;

    return 0;
}
