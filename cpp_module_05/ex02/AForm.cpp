#include "AForm.hpp"

const char*	AForm::GradeTooHighException::what() const throw() {	
	return "The grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "The grade is too low to sign/execute this form";
}

const char*	AForm::FormNotSignedExecption::what() const throw() {
	return "The form is not signed to be executed";
}

AForm::AForm()
	: name("Unnamed"), gradeToSign(50), gradeToExecute(100) {
		this->isSigned = false;
}

AForm::AForm(const AForm& copy)
	: name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
		this->isSigned = copy.isSigned;
}

AForm::AForm(String name, int gradeToSign, int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
		this->isSigned = false;
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw AForm::GradeTooHighException();
		if (gradeToSign > 150 || gradeToExecute > 150)
			throw AForm::GradeTooLowException();
}

AForm&	AForm::operator=(const AForm& other) {
	std::cout << "AForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->isSigned = other.isSigned;
	return *this;
}

void	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

void	AForm::execute(Bureaucrat const& executor) const {
	if (!this->isSigned)
		throw FormNotSignedExecption();
	std:: cout << "gradeToExecute: " << this->gradeToExecute << " | " << "executor: " << executor.getGrade() << std::endl;
	if (this->gradeToExecute < executor.getGrade())
		throw GradeTooLowException();
	action();
}

String AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int	AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

AForm::~AForm() {
	std::cout << "AForm Destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const AForm& form) {
	out << "[" + form.getName() + ", " << form.getIsSigned()
		<< ", " << form.getGradeToSign() << ", " << form.getGradeToExecute()
		<< "]";
	return out;
}