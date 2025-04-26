#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw() {	
	return "The grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is too low!";
}

Bureaucrat::Bureaucrat(): name("Unnamed") {
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.name) {
	this->grade = copy.grade;
}

Bureaucrat::Bureaucrat(String name, int grade): name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return *this;
	this->grade = other.grade;
	return *this;
}

void	Bureaucrat::incrementGrade() {
	int newGrade = this->grade - 1;
	if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = newGrade;
}

void	Bureaucrat::decrementGrade() {
	int newGrade = this->grade + 1;
	if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = newGrade;
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->name + " signed " << form << std::endl;
	} catch (AForm::GradeTooLowException e) {
		std::cout << this->name + " couldn't sign " << form <<
		" because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << "[" << *this << "] executed " << form << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
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