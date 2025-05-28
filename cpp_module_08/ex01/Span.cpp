#include "Span.hpp"

const char*	Span::SpanFullException::what() const throw() {
	return "Cannot add element: Span is already full!";
}

const char*	Span::NoSpanFoundException::what() const throw() {
	return "No span can be found: not enough numbers stored!";
}

Span::Span() {
	this->N = 0;
}

Span::Span(size_t N) {
	this->N = N;
}

Span::Span(const Span& copy) {
	*this = copy;
}

Span&	Span::operator=(const Span& other) {
	if (this == &other)
		return *this;
	this->N = other.N;
	this->vect = other.vect;
	return *this;
}

void	Span::addNumber(int number) {
	if (vect.size() >= N)
		throw SpanFullException();
	vect.push_back(number);
}

int	Span::shortestSpan() {
	int	shortestSpan = INT_MAX;
	std::vector<int>::const_iterator it;

	if (vect.size() <= 1)
		throw NoSpanFoundException();

	for (it = vect.begin(); it != (vect.end() - 1); it++) {
		int current = *it;		
		int next = *(it + 1);
		int span = std::abs(current - next);
		if (span < shortestSpan) 
			shortestSpan = span;
	}
	return shortestSpan;
}

int	Span::longestSpan() {
	int	longestSpan = INT_MIN;
	std::vector<int>::const_iterator it;

	if (vect.size() <= 1)
		throw NoSpanFoundException();

	for (it = vect.begin(); it != (vect.end() - 1); it++) {
		int current = *it;
		int next = *(it + 1);
		int span = std::abs(current - next);
		if (span > longestSpan)
			longestSpan = span;
	}
	return longestSpan;
}

void	Span::printAll() const {
	std::vector<int>::const_iterator it;
	for (it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;
}

Span::~Span() {}