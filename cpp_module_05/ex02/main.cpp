#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main() {
	srand(time(0));
	RobotomyRequestForm form;
	Bureaucrat crat("Fennec", 4);
	form.beSigned(crat);
	form.execute(crat);
}