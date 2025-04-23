#include "Form.hpp"

const char*	Bureaucrat::GradeTooHighException::what() const throw() {	
	return "The grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "The grade is too low to sign this form";
}

Form::Form()
	: name("Unnamed"), gradeToSign(50), gradeToExecute(100) {
		this->isSigned = false;
}

Form::Form(Form& const copy)
	: name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
		this->isSigned = copy.isSigned;
}

Form::Form(String name, int gradeToSign, int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
		this->isSigned = false;
}

Form&	Form::operator=(Form& const other) {
	if (this == &other)
		return *this;
	this->isSigned = other.isSigned;
	return *this;
}

void	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

String Form::getName() const {
	return this->name;
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int	Form::getGradeToSign() const {
	return this->gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->gradeToExecute;
}

Form::~Form() {
	std::cout << "Form Destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const Form& form) {
	out << "[" + form.getName() + ", " << form.getIsSigned()
		<< ", " << form.getGradeToSign() << ", " << form.getGradeToExecute()
		<< "]";
	return out;
}