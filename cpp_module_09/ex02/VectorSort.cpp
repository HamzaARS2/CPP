#include "VectorSort.hpp"
#include <algorithm>

VectorSort::VectorSort() {

}

VectorSort::VectorSort(char **data) {
	int i = 0;
	while (data[i])
		main.push_back(std::atoi(data[i++]));
}

VectorSort::VectorSort(const VectorSort& copy) {
	*this = copy;
}

VectorSort&	VectorSort::operator=(const VectorSort& other) {
	if (this == &other)
		return *this;
	this->v = other.v;
	return *this;
}

void	VectorSort::buildPairs() {
	for (size_t i = 0; i < main.size(); i++) {
		std::pair<int, int> p;
		p.first = main[i++];
		if (i < main.size())
			p.second = main[i];
		v.push_back(p);
	}
}

void	VectorSort::sortPairs() {
	std::cout << "sorting" << std::endl;
	std::vector<std::pair<int, int> >::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		if ((*it).first > (*it).second)
			std::swap((*it).first, (*it).second);
	}
}

void	VectorSort::insert() {
	// insert from pend to main
}

void	VectorSort::sort(std::vector<std::pair<int, int> > v) {
	(void)v;
}

VectorSort::~VectorSort(){}