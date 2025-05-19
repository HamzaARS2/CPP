#include "Student.hpp"

Student::Student() {
    this->name = "Unnamed";
    this->grade = 0;
    this->isPassed = false;
}

Student::Student(String name, float grade) {
    this->name = name;
    this->grade = grade;
    this->isPassed = false;
}

Student::Student(String name, float grade, bool passed) {
    this->name = name;
    this->grade = grade;
    this->isPassed = passed;
}

void Student::setIsPassed(bool passed) {
    this->isPassed = passed;
}
String Student::getName() const {
    return this->name;
}
float Student::getGrade() const {
    return this->grade;
}
bool Student::getIsPassed() const {
    return this->isPassed;
}
Student::~Student() {
    
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Name: " << student.getName() << ", Grade: " << student.getGrade() << ", Passed: " << (student.getIsPassed() ? "Yes" : "No");
    return os;
}