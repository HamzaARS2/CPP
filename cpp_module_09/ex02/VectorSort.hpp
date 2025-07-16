#ifndef VECTOR_SORT_HPP
# define VECTOR_SORT_HPP

#include <iostream>
#include <vector>

class VectorSort {
	public:
		VectorSort();
		VectorSort(const VectorSort& copy);

		VectorSort&	operator=(const VectorSort& other);
		int	jacobOf(int n);
		std::vector<std::pair<int, int> >	buildPairs(std::vector<int> v, int& unpaired);
		void				comparePairs(std::vector<std::pair<int, int> > pairs, std::vector<int>& winners, std::vector<int>& losers);
		std::vector<int>	getOrderedIndexes(std::vector<int> losers);
		int					binarySearch(std::vector<int> v, int e);
		void				binaryInsert(std::vector<int>& winners, std::vector<int>& losers, int unpaired);
		std::vector<int>	sort(std::vector<int> v);
		~VectorSort();
};

#endif