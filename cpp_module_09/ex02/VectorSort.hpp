#ifndef VECTOR_SORT_HPP
# define VECTOR_SORT_HPP

#include "ISorter.hpp"
#include <vector>

class VectorSort: public ISorter {
	public:
		std::vector<std::pair<int, int> > v;
		std::vector<int> main;
		std::vector<int> pend;

		std::vector<int> getOrderedIndexes() const;
		int	jacobOf(int n) const;
		int	binarySearch(int e);
		static bool	compare(std::pair<int, int> p1,std::pair<int, int> p2);
	public:
		VectorSort();
		VectorSort(char **data);
		VectorSort(const VectorSort& copy);

		VectorSort&	operator=(const VectorSort& other);
		// overidden methods
		void	buildPairs();
		void	sortElements();
		void	sortPairs();
		void	generateMainPend();
		void	insert();
		void	sort(std::vector<std::pair<int, int> > v);


		void	printAll() {
			for (size_t i = 0; i < v.size(); i++) {
				std::cout << "[" << v[i].first << ", " << v[i].second << "]" << std::endl;
			}
		}

		void	printMain() {
			std::cout << "main: ";
			for (size_t i = 0; i < main.size(); i++)
				std::cout << " " << main[i];
			std::cout << std::endl;
		}
		void	printPend() {
			std::cout << "pend: ";
			for (size_t i = 0; i < pend.size(); i++)
				std::cout << " " << pend[i];
			std::cout << std::endl;
		}

		~VectorSort();
};

#endif