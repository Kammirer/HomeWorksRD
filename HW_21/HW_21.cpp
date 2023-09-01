#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool compareByLength(const std::string &strBegin, const std::string& strEnd) {
	return strBegin.length() < strEnd.length();
}

class LengthComparator {
public:
	bool operator()(const std::string& strBegin, const std::string& strEnd) {
		return strBegin.length() > strEnd.length();
	}
};

unsigned int countDivisibleBy(const std::vector<int>& Numbers, int number) {
	auto lambdaDivisior = [number](int m_elem) { return m_elem % number == 0; };
	return std::count_if(Numbers.begin(), Numbers.end(), lambdaDivisior);
}

int main()
{
	// == Step 1 ==
	std::vector<std::string> stringContainer = {"Thermite", "Ash", "Castle", "Kali", "Pulse"};

	// == function ==
	std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);
	
	for (const std::string str : stringContainer) {
		std::cout << str << " ";
	}
	std::cout << "\n\n";

	// == class ==
	LengthComparator Comparator;

	std::sort(stringContainer.begin(), stringContainer.end(), Comparator);
	
	for (const std::string str : stringContainer) {
		std::cout << str << " ";
	}
	std::cout << "\n\n";

	// == lambda ==
	auto lambdaFunction = [](const std::string& strBegin, const std::string& strEnd) { return strBegin.length() < strEnd.length(); };
	
	std::sort(stringContainer.begin(), stringContainer.end(), lambdaFunction);

	for (const std::string str : stringContainer) {
		std::cout << str << " ";
	}
	std::cout << "\n\n";

	// == Step 2 ==
	std::vector<int> myNumbers = { 3,55,7,95,1,5,34,62 };
	int m_divisior = 5;

	unsigned int m_count = countDivisibleBy(myNumbers, m_divisior);
	std::cout << m_count << "\n";

	return 0;
}