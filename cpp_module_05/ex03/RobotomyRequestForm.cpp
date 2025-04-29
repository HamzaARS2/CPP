#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:AForm("RobotomyRequestForm", 72, 45) {
	this->target = "Unknown";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	:AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()) {
		this->target = copy.target;
}

RobotomyRequestForm::RobotomyRequestForm(String target)
	:AForm("RobotomyRequestForm", 72, 45) {
		std::cout << "RobotomyRequestForm constructor called" << std::endl;
		this->target = target;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

void	RobotomyRequestForm::action() const {
	std::cout << "* Drilling noises *" << std::endl;
	int robotomize = rand() % 2;
	if (robotomize)
		std::cout << this->target + " has been robotomized!" << std::endl;
	else
		std::cout << "Robotomy failed!" << std::endl;
}

AForm*	RobotomyRequestForm::create(String target) {
	return new RobotomyRequestForm(target);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}