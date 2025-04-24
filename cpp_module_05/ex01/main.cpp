#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	std::cout << "========== Construction ===========" << std::endl;
	Form* easyForm;
	Form* normalForm;
	Form* hardForm;
	Form* invalidForm;

	Bureaucrat fennec("Fennec", 1);
	Bureaucrat octane("Octane", 45);
	Bureaucrat merc("Merc", 101);

	try {
		easyForm = new Form("EasyForm", 150, 120);
		normalForm = new Form("NormalForm", 60, 50);
		hardForm = new Form("HardForm", 5, 2);
		invalidForm = new Form("InvalidForm", 0, 151);
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========== Signing Forms ===========" << std::endl;

	std::cout << "[ High Grade ]" << std::endl;
	fennec.signForm(*easyForm);
	fennec.signForm(*normalForm);
	fennec.signForm(*hardForm);
	
	std::cout << "\n[ Medium Grade ]" << std::endl;
	octane.signForm(*easyForm);
	octane.signForm(*normalForm);
	octane.signForm(*hardForm);

	std::cout << "\n[ Low Grade ]" << std::endl;
	merc.signForm(*easyForm);
	merc.signForm(*normalForm);
	merc.signForm(*hardForm);

	std::cout << "========== Destruction ===========" << std::endl;

	delete easyForm;
	delete normalForm;
	delete hardForm;
}