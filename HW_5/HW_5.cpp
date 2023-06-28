#include <iostream>

enum class Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
    // 1 STEP
    std::cout << "1 STEP: Max number" << std::endl;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    std::cout << "Enter 3 integer number: ";
    std::cin >> num1 >> num2 >> num3;

    if (num1 > num2 && num1 > num3) {
        std::cout << "Max number: " << num1 << std::endl;
    }
    else if (num2 > num1 && num2 > num3) {
        std::cout << "Max number: " << num2 << std::endl;
    }
    else {
        std::cout << "Max number: " << num3 << std::endl;
    }
    std::cout << std::endl;

    // 2 STEP
    std::cout << "2 STEP: Min number" << std::endl;
    int numTern1 = 0;
    int numTern2 = 0;
    int resNum = 0;

    std::cout << "Enter 2 integer number: ";
    std::cin >> numTern1 >> numTern2;

    resNum = (numTern1 < numTern2) ? numTern1 : numTern2;

    std::cout << "Min number: " << resNum << std::endl;
    std::cout << std::endl;

    // 3 STEP
    std::cout << "3 STEP: Dividing a number by 5 and 11"<< std::endl;
    int numDiv = 0;
    int resultModule5 = 0;
    int resultModule11 = 0;
    bool resultDiv;

    std::cout << "Enter your integer number: ";
    std::cin >> numDiv;

    resultModule5 = numDiv % 5;
    resultModule11 = numDiv % 11;

    resultDiv = (resultModule5 == 0) && (resultModule11 == 0);

    if (resultDiv) {
        std::cout << "Resul by div: " << std::boolalpha << resultDiv << std::endl;
    }
    else {
        std::cout << "Resul by div: " << std::boolalpha << resultDiv << std::endl;
    }
    std::cout << std::endl;

    // 4 STEP
    std::cout << "4 STEP: Triangle" << std::endl;
    int angle1 = 0;
    int angle2 = 0;
    int angle3 = 0;
    int sumAngle = 0;

    std::cout << "Enter 3 number: ";
    std::cin >> angle1 >> angle2 >> angle3;

    sumAngle = angle1 + angle2 + angle3;

    if (sumAngle == 180) {
        std::cout << "This is a Triangle!" << std::endl;
    }
    else {
        std::cout << "This is NOT a Triangle!" << std::endl;
    }
    std::cout << std::endl;

    // 5 STEP
    std::cout << "5 STEP: Month by switch-case" << std::endl;
    int month = 0;

    std::cout << "Enter month number (1-12): ";
    std::cin >> month;

    switch (month)
    {
    case int(Month::January):
        std::cout << "January\n";
        break;
    case int(Month::February) :
        std::cout << "February\n";
        break;
    case int(Month::March) :
        std::cout << "March\n";
        break;
    case int(Month::April) :
        std::cout << "April\n";
        break;
    case int(Month::May) :
        std::cout << "May\n";
        break;
    case int(Month::June) :
        std::cout << "June\n";
        break;
    case int(Month::July) :
        std::cout << "July\n";
        break;
    case int(Month::August) :
        std::cout << "August\n";
        break;
    case int(Month::September) :
        std::cout << "September\n";
        break;
    case int(Month::October) :
        std::cout << "October\n";
        break;
    case int(Month::November) :
        std::cout << "November\n";
        break;
    case int(Month::December) :
        std::cout << "December\n";
        break;
    default:
        std::cout << "Error...\n";
    }
    std::cout << std::endl;

    // 6 STEP
    std::cout << "6 STEP: Seasons by switch-case" << std::endl;
    int monthSeason = 0;

    std::cout << "Enter month number (1-12) for season: ";
    std::cin >> monthSeason;

    switch (monthSeason)
    {
    case int(Month::December) :
    case int(Month::January):
    case int(Month::February) :
        std::cout << "Winter\n";
        break;
    case int(Month::March) :
    case int(Month::April) :
    case int(Month::May) :
        std::cout << "Spring\n";
        break;
    case int(Month::June) :
    case int(Month::July) :
    case int(Month::August) :
        std::cout << "Summer\n";
        break;
    case int(Month::September) :
    case int(Month::October) :
    case int(Month::November) :
        std::cout << "Autumn\n";
        break;
    default:
        std::cout << "Error...\n";
    }

    return 0;
}