#ifndef VECTOR_SORT_HPP
# define VECTOR_SORT_HPP

#include "ISorter.hpp"
#include <vector>

class VectorSort: public ISorter {
	private:
		std::vector<std::pair<int, int> > v;
		std::vector<int> main;
		std::vector<int> pend;

	public:
		VectorSort();
		VectorSort(char **data);
		VectorSort(const VectorSort& copy);

		VectorSort&	operator=(const VectorSort& other);
		// overidden methods
		void	buildPairs();
		void	sortPairs();
		void	insert();
		void	sort(std::vector<std::pair<int, int> > v);

		void	printAll() {
			for (size_t i = 0; i < v.size(); i++) {
				std::cout << "[" << v[i].first << ", " << v[i].second << "]" << std::endl;
			}
		}

		~VectorSort();
};

#endif