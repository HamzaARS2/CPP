#include "PmergeMe.hpp"

int	reportError(String msg) {
	std::cerr << "Error: " + msg << std::endl;
	return 1;
}

int	main(int ac, char **av) {
	if (ac <= 1)
		return reportError("Expecting a sequence of positive numbers");

	PmergeMe algo;

	if (!algo.prepareData(++av))
		return reportError("Invalid args");

	algo.sortVector();
	algo.sortDeque();

	algo.displayComparison();
}