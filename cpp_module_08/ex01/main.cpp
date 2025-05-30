#include "Span.hpp"
#include <list>
int	main() {

	std::cout << "========= Simple test =========" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try {
		sp.addNumber(37);
	} catch (Span::SpanFullException& e) {
		std::cout << e.what() << std::endl;
	}
	sp.printAll();
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << "========= Adding an empty range test =========" << std::endl;
	Span sp0 = Span(10);
	std::list<int> empty;
	sp0.addRange(empty.begin(), empty.end());
	sp0.printAll();
	try {
		std::cout << "Shortest span: " << sp0.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp0.longestSpan() << std::endl;
	} catch (Span::NoSpanFoundException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========= Adding a range to a smaller span test =========" << std::endl;
	Span sp1 = Span(3);
	std::vector<int> source1;
	source1.push_back(1);
	source1.push_back(2);
	source1.push_back(3);
	source1.push_back(4);
	source1.push_back(5);
	sp1.addRange(source1.begin(), source1.end());
	sp1.printAll();
	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

	std::cout << "========= Adding 10k elements using range =========" << std::endl;
	Span sp2 = Span(10000);
	std::vector<int> source2(10000, 42);
	sp2.addRange(source2.begin(), source2.end());
	// sp2.printAll();
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	try {
		sp2.addNumber(13);
	} catch (Span::SpanFullException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "========= Adding 100k elements using range =========" << std::endl;
	Span sp3 = Span(100000);
	std::vector<int> source3(100000, 1337);
	sp3.addRange(source3.begin(), source3.end());
	// sp3.printAll();
	std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
}