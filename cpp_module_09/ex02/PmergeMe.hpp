#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

#include <iostream>
#include "VectorSort.hpp"
#include "DequeSort.hpp"
#include <vector>
#include <deque>
#include <time.h>

typedef std::string String;

class PmergeMe {
	private:
		VectorSort			vs;
		DequeSort			ds;
		std::vector<int>	v;
		std::deque<int>		d;
		std::vector<int>	sortedV;
		std::deque<int>		sortedD;
		double				vTime;
		double				dTime;

		bool	isOnlyDigits(String str) const;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);

		PmergeMe&	operator=(const PmergeMe& other);

		bool	prepareData(char **data);
		void	sortVector();
		void	sortDeque();
		void	displayComparison() const;

		std::vector<int>	getSortedVector() const;
		std::deque<int>		getSortedDeque() const;

		~PmergeMe();
};

#endif