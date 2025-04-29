#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	srand(time(0));
	std::cout << "========== Construction ===========\n" << std::endl;
	Intern intern;

	AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Garden");
	AForm* robotomyForm = intern.makeForm("robotomy request", "Home");
	AForm* presidentialForm = intern.makeForm("presidential pardon", "Pardon");
	
	AForm* coffeeRequestForm = intern.makeForm("coffee request", "Cafe");
	(void)coffeeRequestForm;

	Bureaucrat fennec("Fennec", 5);
	Bureaucrat octane("Octane", 45);
	Bureaucrat merc("Merc", 137);

	std::cout << "========== Executing Unsigned Forms ===========\n" << std::endl;

	merc.executeForm(*shrubberyForm);
	octane.executeForm(*robotomyForm);
	fennec.executeForm(*presidentialForm);

	std::cout << "========== Signing Forms ===========\n" << std::endl;
	
	try {
		shrubberyForm->beSigned(merc);
		robotomyForm->beSigned(octane);
		presidentialForm->beSigned(fennec);
	}
	catch(AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "========== Executing Signed Forms ===========\n" << std::endl;
	std::cout << "=== [ Fennec ] ===\n" << std::endl;

	fennec.executeForm(*shrubberyForm);
	fennec.executeForm(*robotomyForm);
	fennec.executeForm(*presidentialForm);

	std::cout << "=== [ Octane ] ===\n" << std::endl;

	octane.executeForm(*shrubberyForm);
	octane.executeForm(*robotomyForm);
	octane.executeForm(*presidentialForm);

	std::cout << "=== [ Octane ] ===\n" << std::endl;

	merc.executeForm(*shrubberyForm);
	merc.executeForm(*robotomyForm);
	merc.executeForm(*presidentialForm);

	std::cout << "========== Destruction ===========\n" << std::endl;

	delete shrubberyForm;
	delete robotomyForm;
	delete presidentialForm;
}