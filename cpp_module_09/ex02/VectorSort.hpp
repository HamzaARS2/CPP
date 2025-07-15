#ifndef VECTOR_SORT_HPP
# define VECTOR_SORT_HPP

#include "ISorter.hpp"
#include <vector>

class VectorSort: public ISorter {
	public:
		VectorSort();
		VectorSort(const VectorSort& copy);

		VectorSort&	operator=(const VectorSort& other);
		// overidden methods

		~VectorSort();
};

#endif