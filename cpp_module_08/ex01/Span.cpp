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
	std::vector<int> diffResult;
	std::vector<int>::iterator it;

	if (vect.size() <= 1)
		throw NoSpanFoundException();
	std::adjacent_difference(vect.begin(), vect.end(), std::back_inserter(diffResult));
	for (it = diffResult.begin(); it != diffResult.end(); it++)
		*it = std::abs(*it);

	return *std::min_element(diffResult.begin() + 1, diffResult.end());
}

int	Span::longestSpan() {
	std::vector<int> diffResult;
	std::vector<int>::iterator it;

	if (vect.size() <= 1)
		throw NoSpanFoundException();
	std::adjacent_difference(vect.begin(), vect.end(), std::back_inserter(diffResult));
	for (it = diffResult.begin(); it != diffResult.end(); it++)
		*it = std::abs(*it);

	return *std::max_element(diffResult.begin() + 1, diffResult.end());
}

size_t	Span::getSize() const {
	return vect.size();
}

void	Span::printAll() const {
	std::vector<int>::const_iterator it;
	for (it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << std::endl;
}

Span::~Span() {}