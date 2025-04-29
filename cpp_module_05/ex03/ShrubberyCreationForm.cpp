#include "ShrubberyCreationForm.hpp"


const char*	ShrubberyCreationForm::FileOpenException::what() const throw() {
	return "The file can't be opened";
}

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("RobotomyRequestForm", 145, 137) {
	this->target = "Unknown";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	: AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()) {
		this->target = copy.target;
}

ShrubberyCreationForm::ShrubberyCreationForm(String target)
	:AForm("ShrubberyCreationForm", 145, 137) {
		std::cout << "ShrubberyCreationForm constructor called" << std::endl;
		this->target = target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->target = other.target;
	return *this;
}

void	ShrubberyCreationForm::action() const {
	std::ofstream out;
	String filename = this->target + "_shrubbery";

	out.open(filename);
	if (!out.is_open())
		throw FileOpenException();
	// building tree
	int height = 8;
	for (int i = 0; i <= height; i++) {
		int width = 6 + i;
		for (int k = 0; k <= width; k++) {
			if (k + i >= width - i && i < height - 1)
				out << "*";
			else if (i >= height - 1 && k >= 5 && k <= 7)
				out << "|";
			else
				out << " ";
		}
		out << std::endl;
	}
	// closing the stream
	out.close();
}

AForm*	ShrubberyCreationForm::create(String target) {
	return new ShrubberyCreationForm(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}