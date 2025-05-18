#ifndef STUDENT_HPP
# define STUDENT_HPP

#include <iostream>
typedef std::string String;

class Student {
	private:
		String name;
		float grade;
		bool isPassed;
	
	public:
		Student(String name, float grade);
		void	setIsPassed(bool passed);

		String getName() const;
		float getGrade() const;
		bool	getIsPassed() const;
		~Student();
};

std::ostream& operator<<(std::ostream& os, const Student& student);

#endif