#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>
#include <stack>

unsigned int uniqueWordsCount(const std::string& line) {
	if (!line.empty()) {
		std::stringstream iss(line);
		std::set<std::string> words;
		
		std::string word;
		while (iss >> word) {
			words.insert(word);
		}
		
		return words.size();
	}
	else {
		return 0;
	}
}

std::string mostOccuredWord(const std::string& line) {
	if (!line.empty()) {
		std::unordered_map<std::string, int> words;
		std::stringstream iss(line);
		
		std::string word;
		while (iss >> word) {
			words[word]++;
		}

		std::string outWord;
		int maxCount = 0;

		for (const auto& pair : words) {
			if (pair.second > maxCount) {
				maxCount = pair.second;
				outWord = pair.first;
			}
		}

		return outWord;
	}
	else {
		return "Line is empty!";
	}
}

bool areBalanced(const std::string& line) {
	std::stack<char> myStack;

	for (char ch : line) {
		if (ch == '(' || ch == '[' || ch == '{') {
			myStack.push(ch);
		}
		else if (ch == ')' || ch == ']' || ch == '}') {
			if (myStack.empty()) {
				return false;
			}

			char top = myStack.top();
			myStack.pop();

			if ( (top != '(' && ch == ')') ||
				 (top != '[' && ch == ']') ||
				 (top != '{' && ch == '}') ) {
				return false;
			}
		}
	}

	return myStack.empty();
}


int main()
{
	std::string line = "By Hello Vector Bike By Line Hello Bye Coding Line By";
	
	// == set ==
	std::cout << "Number of unique words in line: " << uniqueWordsCount(line) << "\n\n";

	// == map ==
	std::cout << "Most occured word in line: " << mostOccuredWord(line) << "\n\n";

	// == stack ==
	std::string firstLineStack = "{ [()][ ] }()";
	std::cout << "Line: \"" << firstLineStack << "\" is balanced? ";

	if (areBalanced(firstLineStack)) {
		std::cout << "YES\n" << std::endl;
	}
	else {
		std::cout << "NO\n" << std::endl;
	}
	
	std::string secondLineStack = "[{]}";
	std::cout << "Line: \"" << secondLineStack << "\" is balanced? ";

	if (areBalanced(secondLineStack)) {
		std::cout << "YES\n" << std::endl;
	}
	else {
		std::cout << "NO\n" << std::endl;
	}

	return 0;
}