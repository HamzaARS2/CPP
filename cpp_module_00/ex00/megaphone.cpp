#include <iostream>

int	main(int ac, char **av) {
	for (int i = 1; i < ac; i++)
		for (int k = 0; av[i][k]; k++)
			std::cout << (char)std::toupper(av[i][k]);
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}
