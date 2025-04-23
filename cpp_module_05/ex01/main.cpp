#include "Bureaucrat.hpp"

int	main() {
	std::cout << "========== Construction ===========" << std::endl;
	try {
		Bureaucrat toLow("stuipedBoy", 151);
		Bureaucrat toHigh("not from this world", 0);
	} catch(Bureaucrat::GradeTooLowException e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "========== Looping ===========" << std::endl;
	Bureaucrat crat("Hamza", 20);
	Bureaucrat crat2("Hamza2", 130);
	for (int i = 0; i < 20; i++) {
		try {
			std::cout << crat << std::endl;
			std::cout << crat2 << std::endl;
			crat.incrementGrade();
			crat2.decrementGrade();
		} catch(Bureaucrat::GradeTooHighException e) {
			std::cout << e.what() << std::endl;
		} catch(Bureaucrat::GradeTooLowException e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "========== After ===========" << std::endl;
	try {
		crat2.decrementGrade();
		std::cout << crat2 << std::endl;
		crat2.decrementGrade();
		std::cout << crat2 << std::endl;
	} catch (Bureaucrat::GradeTooLowException e) {
		std::cout << e.what() << std::endl;
	}
}