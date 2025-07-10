#include "VectorSort.hpp"

int	main(int ac, char **av) {
	if (ac <= 1)
		return 1;
	VectorSort vs(++av);
	vs.buildPairs();
	vs.printAll();
	vs.sortPairs();
	vs.printAll();

}