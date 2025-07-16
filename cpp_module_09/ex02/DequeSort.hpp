#ifndef DEQUE_SORT_HPP
# define DEQUE_SORT_HPP

#include <iostream>
#include <deque>

class DequeSort {
	public:
		DequeSort();
		DequeSort(const DequeSort& copy);

		DequeSort&	operator=(const DequeSort& other);
		int	jacobOf(int n);
		std::deque<std::pair<int, int> >	buildPairs(std::deque<int> v, int& unpaired);
		void				comparePairs(std::deque<std::pair<int, int> > pairs, std::deque<int>& winners, std::deque<int>& losers);
		std::deque<int>	getOrderedIndexes(std::deque<int> losers);
		int					binarySearch(std::deque<int> v, int e);
		void				binaryInsert(std::deque<int>& winners, std::deque<int>& losers, int unpaired);
		std::deque<int>	sort(std::deque<int> v);
		
		~DequeSort();
};

#endif