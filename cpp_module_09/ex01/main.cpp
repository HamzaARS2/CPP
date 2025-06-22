#include "RPN.hpp"


// bool	validateExpression(String expression) {
// }

int	main(int ac, char **av) {
	if (ac <= 1) {
		std::cerr << "missing operation" << std::endl;
		return 1;
	}

	RPN rpn(av[1]);
	rpn.solve();
	rpn.showResult();
}