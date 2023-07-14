#include <cstring>

// Step 1
void translateArray(int numbers[], int size) {
	for (int i = 0; i < size; i++) {
		if (numbers[i] > 0) {
			numbers[i] *= 2;
		}
		else {
			numbers[i] = 0;
		}
	}
}

// Step 2
void toUppercase(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - 32;
		}
		i++;
	}
}

// Step 3
bool isPalindrom(const char str[]) {
	int length = strlen(str);
	int startLine = 0;
	int endLine = length - 1;

	while (startLine < endLine) {
		if (str[startLine] != str[endLine]) {
			return false;
		}
		startLine++;
		endLine--;
	}

	return true;
}

// Step 4
void parseStringLetters(const char str[], int& vowelsCount, int& constonantsCount) {
	int i = 0;
	while (str[i] != '\0') {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
				str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
				vowelsCount++;
			}
			else {
				constonantsCount++;
			}
		}
		i++;
	}
}

// Step 5
bool isEqual(const char str1[], const char str2[]) {
	for (int i = 0; i < 100; i++) {
		if (str1[i] != str2[i]) {
			return false;
			break;
		}
	}

	return true;
}