#include "Bureaucrat.hpp"



const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	String msg = "The Grade is higher than 150!";
	return msg.c_str();
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	String msg = "The Grade is lower than 1!";
	return msg.c_str();
}

Bureaucrat::Bureaucrat(): name("Unnamed") {
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.name) {
	this->grade = copy.grade;
}

Bureaucrat::Bureaucrat(String name, int grade): name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return *this;
	this->grade = other.grade;
	return *this;
}

void	Bureaucrat::incrementGrade() {
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (this->grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	this->grade++;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (this->grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

String	Bureaucrat::getName() const {
	return this->name;
}

int	Bureaucrat::getGrade() const {
	return this->grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() + ", bureaucrat grade "
		<< bureaucrat.getGrade();
	return out;
}