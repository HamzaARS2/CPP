#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	srand(time(0));
	PresidentialPardonForm form;
	Bureaucrat crat("Fennec", 4);
	form.beSigned(crat);
	form.execute(crat);
}