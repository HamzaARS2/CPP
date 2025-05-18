#ifndef USER_HPP
# define USER_HPP

#include <iostream>
typedef std::string String;

class User {
	private:
		String name;
		float grade;
		bool isPassed;
	
	public:
		User(String name, float grade);
		void	setIsPassed(bool passed);

		String getName() const;
		float getGrade() const;
		bool	getIsPassed() const;
		~User();
};

#endif