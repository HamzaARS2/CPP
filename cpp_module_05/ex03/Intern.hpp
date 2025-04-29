#ifndef INTERN_HPP
# define INTERN_HPP


#include "AForm.hpp"

struct FormPair {
	String name;
	AForm* (*create)(String);
};

class Intern {
	private:
		FormPair formPairs[3];

		AForm*	createShrubberyForm(String target);
		AForm*	createRobotomyForm(String target);
		AForm*	createPresidentialForm(String target);

	public:
		Intern();
		Intern(const Intern& copy);

		Intern&	operator=(const Intern& other);

		AForm*	makeForm(String name, String target);

		~Intern();
};


#endif