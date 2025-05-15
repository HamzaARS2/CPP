#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base*	generate(void) {
	std::cout << "Generating..." << std::endl;
	int i = rand() % 3;
	switch (i) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return nullptr;
}

void	identify(Base* p) {
	std::cout << "Identifying Base pointer type" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else 
		std::cout << "Can't be identified: not a subclass of base" << std::endl;
}

void	identify(Base& p) {
	std::cout << "Identifying Base reference type" << std::endl;
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (const std::bad_cast& e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		} catch (std::bad_cast& e) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			} catch (std::bad_cast& e) {
				std::cerr << "Can't be identified: not a subclass of base" << std::endl;
			}
		}
	}
}

int	main() {
	srand(time(NULL));
	Base* b = generate();
	Base* base = new Base();

	identify(b);
	identify(*b);
	identify(base);
	
	delete b;
	delete base;
}

