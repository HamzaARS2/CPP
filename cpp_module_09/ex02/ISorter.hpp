#ifndef ISORTER_HPP
# define ISORTER_HPP

#include <iostream>
#include <vector>
typedef std::string String;

class ISorter {
	public:
		virtual void	buildPairs() = 0;
		virtual void	sortPairs() = 0;
		virtual void	insert() = 0;
		virtual	void	sort(std::vector<std::pair<int, int> > v) = 0;
		// virtual ~ISorter () = 0;
};

#endif