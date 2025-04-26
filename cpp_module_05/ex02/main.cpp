#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	ShrubberyCreationForm form;
	Bureaucrat crat("Fennec", 4);
	form.beSigned(crat);
	form.execute(crat);
}