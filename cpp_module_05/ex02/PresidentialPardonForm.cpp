#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:AForm("PresidentialPardonForm", 25, 5) {
	this->target = "Unknown";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
	:AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()) {
		this->target = copy.target;
}

PresidentialPardonForm::PresidentialPardonForm(String target)
	:AForm("PresidentialPardonForm", 25, 5) {
		std::cout << "PresidentialPardonForm constructor called" << std::endl;
		this->target = target;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

void	PresidentialPardonForm::action() const {
	std::cout << this->target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}