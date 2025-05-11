#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Invalid input" << std::endl;
		return 1;
	}
	(void)av;

	
	ScalarConverter::convert(av[1]);
	
	// std::cout << &c << std::endl;
	// std::cout << reinterpret_cast<float*>(&c) << std::endl;
	// long f = 0;
	// long *ptrf = &f;
	// 	*ptrf = *(reinterpret_cast<long* >(&c));
	// 	std::cout << *ptrf << std::endl;
		// std::cout <<  << std::endl;
	// std::cout << static_cast<double>( *(reinterpret_cast<double*>(&c))) << std::endl;


}