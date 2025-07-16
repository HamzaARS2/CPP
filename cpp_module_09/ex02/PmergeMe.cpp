#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	*this = copy;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return *this;
	this->v = other.v;
	this->d = other.d;
	this->vs = other.vs;
	this->ds = other.ds;
	return *this;
}

bool	PmergeMe::isOnlyDigits(String str) const {
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); i++) {
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	PmergeMe::prepareData(char **data) {
	int i = 0;

	while (data[i]) {
		if (!isOnlyDigits(data[i]))
			return false;
		int n = std::atoi(data[i++]);
		if (n < 0) return false;
		v.push_back(n);
		d.push_back(n);
	}
	return true;
}

void	PmergeMe::sortVector() {
	clock_t start = clock();
	sortedV = vs.sort(v);
	clock_t end = clock();
	vTime = (double(end - start) / CLOCKS_PER_SEC) * 1e6;
}

void	PmergeMe::sortDeque() {
	clock_t start = clock();
	sortedD = ds.sort(d);
	clock_t end = clock();
	dTime = (double(end - start) / CLOCKS_PER_SEC) * 1e6;
}

void	PmergeMe::displayComparison() const {
	std::cout << "Before: ";
	for (size_t i = 0 ; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0 ; i < sortedV.size(); i++)
		std::cout << sortedV[i] << " ";
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);

	std::cout << "Time to process a range of " << sortedV.size()
		<< " elements with std::vector : " << vTime << " us"<< std::endl;

	std::cout << "Time to process a range of " << sortedD.size()
		<< " elements with std::deque : " << dTime << " us" << std::endl;
}

std::vector<int>	PmergeMe::getSortedVector() const {
	return this->sortedV;
}

std::deque<int>	PmergeMe::getSortedDeque() const {
	return this->sortedD;
}


PmergeMe::~PmergeMe() {
	v.clear();
	d.clear();
}

