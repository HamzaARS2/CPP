#include "Span.hpp"

int	main() {
	Span sp = Span(10000);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	// sp.addNumber(11);
	std::vector<int> source(1000000, 1337);
	sp.addRange(source.begin(), source.end());
	sp.printAll();
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Shortest span: " << sp.longestSpan() << std::endl;
}
