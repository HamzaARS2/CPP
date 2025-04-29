#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern constructor called" << std::endl;
	FormPair shrubberyPair = {"shrubbery creation", ShrubberyCreationForm::create};
	FormPair robotomyPair = {"robotomy request", RobotomyRequestForm::create};
	FormPair presidentalPair = {"presidential pardon", PresidentialPardonForm::create};

	this->formPairs[0] = shrubberyPair;
	this->formPairs[1] = robotomyPair;
	this->formPairs[2] = presidentalPair;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern constructor called" << std::endl;
	for (int i = 0; i < 3; i++)
		this->formPairs[i] = other.formPairs[i];
}

Intern&	Intern::operator=(const Intern& other) {
	(void) other;
	return *this;
}

AForm*	Intern::makeForm(String name, String target) {
	for (int k = 0; k < 3; k++) {
		if (formPairs[k].name == name)
			return formPairs[k].create(target);
	}
	std::cout << name + " is an invalid form name!" << std::endl;
	return NULL;
}


Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}