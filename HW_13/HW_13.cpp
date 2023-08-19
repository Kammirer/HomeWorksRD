#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

int typeGM() {
	int typeGameMode = 0;

	std::cout << "1 - If you want to guess the Wod of the day\n";
	std::cout << "2 - Guess the random word\n";
	std::cout << "0 - Exit the game!\n\n";

	std::cout << "Select the type of game: ";
	std::cin >> typeGameMode;
	std::cin.get();

	return typeGameMode;
}

void printWordResult(const char* guessWord, const char* inputWord) {
	const int lengthQuess = std::strlen(guessWord);
	for (int i = 0; i < lengthQuess; i++) {
		char ch = std::toupper(inputWord[i]);
		if (std::toupper(guessWord[i] == ch)) {
			std::cout << ch;
		}
		else if (std::strchr(guessWord, ch) != nullptr) {
			std::cout << char(std::tolower(ch));
		}
		else {
			std::cout << "*";
		}
	}
	std::cout << "\n";
}

bool successWord(const char* guessWord, const char* inputWord) {
	const int lengthQuess = std::strlen(guessWord);
	const int lengthInput = std::strlen(inputWord);
	if (lengthQuess != lengthInput) {
		return false;
	}
	else {
		for (int i = 0; i < lengthQuess; i++) {
			if (guessWord[i] != inputWord[i]) {
				return false;
			}
		}
	}
	return true;
}

void writeFile(const char* fileName, const char* buf)
{
	std::fstream file;
	file.open(fileName, std::ios::out); //std::ios::trunc , std::ios::app , std::ios::out

	if (!file)
	{
		std::cout << "File not created!\n";
	}
	else
	{
		file << buf;
	}

	file.close();
}

bool checkEOF(const char* fileName) {

	std::fstream file;
	file.open(fileName, std::ios::in);

	if (!file)
	{
		std::cout << "File not found!\n";
	}
	else
	{
		while (!file.eof())
		{

			if (file.peek() == EOF) {
				file.close();
				return true;
			}
			else {
				file.close();
				return false;
			}
		}
	}
}

bool readVerifyFile(const char* fileName, const char* buf) {

	std::fstream file;
	file.open(fileName, std::ios::in);

	const int max_length = 5;
	char buffer[max_length];

	if (!file)
	{
		std::cout << "File not found!\n";
	}
	else
	{
		file.getline(buffer, max_length);
		file.close();
	}

	return successWord(buffer, buf);
}

int main()
{
	const int wordsCount = 10;
	const char* wordBase[wordsCount] = { "APPLE", "NIGHT", "HELLO", "BRAIN", "CAMEL", "WOMAN", "MONEY", "FLAME", "LEVEL", "FRESH" };

	int randNumber = 0;
	const char* guessWord = {};

	const int length = 50;
	char inputWord[length];

	int typeGame = 0;
	int maxSteps = 5;

	//************

	const int MAX_LINES = 31;
	const int MAX_LINE_LENGTH = 6;

	char lines[MAX_LINES * MAX_LINE_LENGTH];
	int numLines = 0;

	std::cout << "Hello! I am a game =SLOVKO=\n";
	std::cout << "You have " << maxSteps << " attempts to guess the Word!\n\n";

	srand(time(nullptr));

	while (true) {

		int steps = 0;
		typeGame = typeGM();

		if (typeGame == 1) {

			time_t now = time(0);
			struct tm tstruct;
			char buf[15];
			localtime_s(&tstruct, &now);
			strftime(buf, sizeof(buf), "%d-%m-%Y", &tstruct);

			if (checkEOF("wordDayResult.txt") || !(readVerifyFile("wordDayResult.txt", buf))) { // if file is empty or date in file != today, play game

				std::time_t t = std::time(nullptr);
				std::tm* now = std::localtime(&t);

				std::fstream file;
				file.open("wordDayBase.txt", std::ios::in);

				if (!file) {
					std::cout << "File not found!\n";
					break;
				}
				else {
					while (numLines < MAX_LINES && file.getline(&lines[numLines * MAX_LINE_LENGTH], MAX_LINE_LENGTH)) {
						numLines++;
					}
				}
				file.close();

				randNumber = rand() % (MAX_LINES);
				guessWord = &lines[randNumber * MAX_LINE_LENGTH]; // Our word of day

				do {

					std::cout << "\nEnter your Word: ";
					std::cin.getline(inputWord, length);
					steps++;

					if (successWord(guessWord, inputWord)) {
						std::cout << "\n== Congratulations! ==" << "\n";
						std::cout << "Word of the day is: " << guessWord << ", you guess it in " << steps << " tries!\n\n";
						steps = 0;
						// wright to file
						writeFile("wordDayResult.txt", buf);
						//
						break;
					}
					else {
						std::cout << "Result input: ";
						printWordResult(guessWord, inputWord);
					}

					if (steps == maxSteps) {
						std::cout << "Sorry, you don`t guess Word of the day... Try again.\n\n";
						steps = 0;
						break;
					}

				} while (steps < maxSteps);
			}
			else { // else - word day guessed
				std::cout << "Sorry. The word of the day has already been guessed goodbye! Came back tomorrow.\n\n";
				steps = 0;
			}
		}

		if (typeGame == 2) {
			randNumber = rand() % (wordsCount);
			guessWord = wordBase[randNumber];

			do {

				std::cout << "\nEnter your Word: ";
				std::cin.getline(inputWord, length);
				steps++;

				if (successWord(guessWord, inputWord)) {
					std::cout << "\n== Congratulations! ==" << "\n";
					std::cout << "My Word is: " << guessWord << ", you guess it in " << steps << " tries!\n\n";
					steps = 0;
					break;
				}
				else {
					std::cout << "Result input: ";
					printWordResult(guessWord, inputWord);
				}

				if (steps == maxSteps) {
					std::cout << "Sorry, you don`t guess my Word.. It was: " << guessWord << "\n\n";
					steps = 0;
					break;
				}

			} while (steps < maxSteps);
		}

		if (typeGame == 0) {
			std::cout << "\nCome back soon! Good luck!\n";
			steps = 0;
			break;
		}

	}

	return 0;
}