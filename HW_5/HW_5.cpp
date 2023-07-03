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

enum class Seasons {
    Winter,
    Spring,
    Summer,
    Autumn
};

int main()
{
    // 1 STEP
    std::cout << "1 STEP: Max number" << std::endl;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int maxNum = 0;

    std::cout << "Enter 3 integer number: ";
    std::cin >> num1 >> num2 >> num3;

    maxNum = num1;
    if (num2 > maxNum) {
        maxNum = num2;
    }
    else if (num3 > maxNum) {
        maxNum = num3;
    }
    std::cout << "Max number: " << maxNum << std::endl;
    
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
        if (angle1 <= 0 || angle2 <= 0 || angle3 <= 0) {
            std::cout << "This is NOT a Triangle!";
        }
        else {
            std::cout << "This is a Triangle!";
        }
    }
    else {
        std::cout << "This is NOT a Triangle!";
    }
    std::cout << std::endl;

    // 5 STEP
    std::cout << "5 STEP: Month by switch-case" << std::endl;
    int monthNumber = 0;

    std::cout << "Enter month number (1-12): ";
    std::cin >> monthNumber;

    Month month;

    switch (monthNumber) {
    case 1:
        month = Month::January;
        std::cout << "January\n";
        break;
    case 2:
        month = Month::February;
        std::cout << "February\n";
        break;
    case 3:
        month = Month::March;
        std::cout << "March\n";
        break;
    case 4:
        month = Month::April;
        std::cout << "April\n";
        break;
    case 5:
        month = Month::May;
        std::cout << "May\n";
        break;
    case 6:
        month = Month::June;
        std::cout << "June\n";
        break;
    case 7:
        month = Month::July;
        std::cout << "July\n";
        break;
    case 8:
        month = Month::August;
        std::cout << "August\n";
        break;
    case 9:
        month = Month::September;
        std::cout << "September\n";
        break;
    case 10:
        month = Month::October;
        std::cout << "October\n";
        break;
    case 11:
        month = Month::November;
        std::cout << "November\n";
        break;
    case 12:
        month = Month::December;
        std::cout << "December\n";
        break;
    default:
        std::cout << "Error..!\n";
        return 0;
    }
    std::cout << std::endl;

    // 6 STEP
    std::cout << "6 STEP: Seasons by switch-case" << std::endl;
    int monthSeason = 0;

    std::cout << "Enter month number (1-12) for season: ";
    std::cin >> monthSeason;

    Seasons season;

    switch (monthSeason)
    {
    case 12:
    case 1:
    case 2:
        season = Seasons::Winter;
        std::cout << "Winter\n";
        break;
    case 3:
    case 4:
    case 5:
        season = Seasons::Spring;
        std::cout << "Spring\n";
        break;
    case 6:
    case 7:
    case 8:
        season = Seasons::Summer;
        std::cout << "Summer\n";
        break;
    case 9:
    case 10:
    case 11:
        season = Seasons::Autumn;
        std::cout << "Autumn\n";
        break;
    default:
        std::cout << "Error...\n";
    }

    return 0;
}