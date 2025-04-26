#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	srand(time(0));
	PresidentialPardonForm form;
	Bureaucrat crat("Fennec", 5);
	form.beSigned(crat);
	crat.executeForm(form);
}