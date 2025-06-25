#include "RPN.hpp"
#include "RPNValidator.hpp"


int	main(int ac, char **av) {
	if (ac <= 1) {
		std::cerr << "missing expression" << std::endl;
		return 1;
	}
	String expression = av[1];
	if (!RPNValidator::validate(expression))
		return 1;
	RPN rpn;
	rpn.setExpression(expression);
	rpn.solve();
	rpn.showResult();
}