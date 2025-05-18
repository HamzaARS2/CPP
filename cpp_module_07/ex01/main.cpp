#include "iter.hpp"
#include <cmath>
#include "Student.hpp"

void	toUpperCase(String& str) {
	for (size_t i = 0; i < str.length(); i++)
		str.at(i) = std::toupper(str.at(i));
}

void roundInPlace(float& x) {
    x = roundf(x);
}

void	squareInt(int& n) {
	n *= n;
}

void	checkStudentPassed(Student& student) {
	int gradeToPass = 10;
	student.setIsPassed(student.getGrade() >= gradeToPass);
}


int	main() {
	// Array of strings
	String strings[] = {"Fennec", "Octane", "Merc"};
	iter(strings,3 ,toUpperCase);
	printAny(strings, 3);

	// Array of floats
	float floats[] = {32.99f, 13.37f, 1.5f, 7338.6f};
	iter(floats, 4, roundInPlace);
	printAny(floats, 4);
	
	// Array of ints
	int numbers[] = {1, 2, 3, 4, 5};
	iter<int, void (int&)>(numbers, 5, squareInt);
	printAny(numbers, 5);

	// Array of Students
	Student students[] = {Student("Klock", 10), Student("Lorem", 19), Student("Merol", 7)};
	iter(students, 3, checkStudentPassed);
	printAny(students, 3);
}