#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat crat("Hamza", 150);

	std::cout << crat << std::endl;
	for (int i = 0; i < 151; i++) {
		try {
			crat.incrementGrade();
			std::cout << crat << std::endl;
		} catch(Bureaucrat::GradeTooLowException e) {
			std::cout << e.what() << std::endl;
		} catch(Bureaucrat::GradeTooHighException e) {
			std::cout << e.what() << std::endl;
		}
	}
}