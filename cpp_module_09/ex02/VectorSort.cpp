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

VectorSort::~VectorSort(){}