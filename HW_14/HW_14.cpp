#include <iostream>

const int sizeMarks = 4;
const float percentForBest = 75.0;

struct Student
{
	const char* name;
	int marks[sizeMarks];
};

double calcAverage(const Student& student) {
	double sumMarks = 0;
	double averageMark = 0;

	for (int i = 0; i < sizeMarks; i++) {
		sumMarks += student.marks[i];
	}

	averageMark = sumMarks / sizeMarks;

	return averageMark;
}

void sortStudentsByAverage(Student students[], int numStudents) {
	for (int i = 0; i < numStudents - 1; i++) {
		for (int j = 0; j < numStudents - i - 1; j++) {
			if (calcAverage(students[j]) < calcAverage(students[j + 1])) {
				std::swap(students[j], students[j + 1]);
			}
		}
	}
}

const Student& bestStudentFunc(Student students[], int numStudents) {
	int best = 0;
	double bestAverage = calcAverage(students[0]);

	for (int i = 1; i < numStudents; i++) {
		double average = calcAverage(students[i]);
		if (average > bestAverage) {
			best = i;
			bestAverage = average;
		}
	}

	return students[best];
}

int count75Percent(Student students[], int numStudents) {
	int numSt = 0;

	for (int i = 0; i < numStudents; i++) {
		double average = calcAverage(students[i]);
		if (average > percentForBest) {
			numSt++;
		}
	}

	return numSt;
}

int main()
{

	const int sizeSt = 5;
	Student students[sizeSt] = { {"Max",  {90, 78, 65, 97}},
								 {"Ron",  {74, 45, 74, 81}},
								 {"John", {60, 89, 91, 72}},
								 {"Eva",  {81, 73, 81, 70}},
								 {"Mark", {63, 72, 69, 65}} };

	// Sort students and print with average mark
	sortStudentsByAverage(students, sizeSt);

	for (int i = 0; i < sizeSt; i++) {
		std::cout << students[i].name << " - ";
		for (int j = 0; j < sizeMarks; j++) {
			std::cout << students[i].marks[j] << " ";
		}
		std::cout << "- average mark: " << calcAverage(students[i]) << std::endl;
	}

	std::cout << std::endl;

	// Best student and print his name
	const Student& bestStudent = bestStudentFunc(students, sizeSt);
	std::cout << "Best student: " << bestStudent.name << std::endl;

	std::cout << std::endl;

	// Amount of students with average marks > 75%
	int studentsPercent = count75Percent(students, sizeSt);
	std::cout << "Amount of students with average marks > 75%: " << studentsPercent << std::endl;

	return 0;
}