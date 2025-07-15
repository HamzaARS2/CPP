#ifndef ISORTER_HPP
# define ISORTER_HPP

#include <iostream>
#include <vector>
typedef std::string String;

template <typename T>
class ISorter {
	private:
		static int	jacobOf(int n);
		static int	binarySearch(std::vector<int> v, int e);

	public:
		virtual typename T<std::pair<int, int> >	buildPairs(T c, int& unpaired) = 0;
		virtual void	classifyPairs(typename T<std::pair<int, int> > pairs, T& winners, T& losers) = 0;
		virtual void	generateOrderedIndexes(T ) = 0;
		virtual void	insert() = 0;
		virtual	void	sort(std::vector<std::pair<int, int> > v) = 0;

		// virtual ~ISorter () = 0;
};

#endif