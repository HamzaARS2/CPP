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
		if (i < main.size() - 1) p.second = main[i];
		else p.second = -1;
		v.push_back(p);
	}
	main.clear();
}


void	VectorSort::sortElements() {
	std::cout << "sorting elements" << std::endl;
	std::vector<std::pair<int, int> >::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		if ((*it).first > (*it).second)
			std::swap((*it).first, (*it).second);
	}
}

bool	VectorSort::compare(std::pair<int, int> p1, std::pair<int, int> p2) {
	// if (p1.first == -1)
	// 	return false;
	return p1.second < p2.second;
}

void	VectorSort::sortPairs() {
	std::cout << "sorting pairs" << std::endl;
	std::sort(v.begin(), v.end(), compare);
}

void	VectorSort::generateMainPend() {
	// generate the main from the v pairs
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].second >= 0 && v[i].first  != -1)
			main.push_back(v[i].second);
		if (v[i].first >= 0)
			pend.push_back(v[i].first);
	}
}

int	VectorSort::jacobOf(int n) const {
	if (n == 0 || n == 1)
		return n;
	return jacobOf(n - 1) + (2 * jacobOf(n - 2));
}

// 0 1 1 3 5 11
std::vector<int> VectorSort::getOrderedIndexes() const {
	// 3 2 5 4
	std::vector<int> indexes;
	for (size_t n = 3; n <= pend.size(); n++) {
		int jn = jacobOf(n);
		indexes.push_back(jn - 1);
		int prevJ = jacobOf(n - 1);
		for (int i = jn - 1; i > prevJ; i--)
			indexes.push_back(i - 1);
	}
	return indexes;
}

int	VectorSort::binarySearch(int e) {
	// search 2
	// 2 7 8 46 53 100
	int l = 0, r = main.size() - 1;
	int m;
	while (l <= r) {
		int size = r - l;
		m = l + (size / 2);
		if (e > main[m]) 
			l = m + 1;
		else if (e < main[m]) 
			r = m - 1;
		else 
			return m;
	}
	return m;
}

void	VectorSort::insert() {
	// insert from pend to main
	if (pend.empty())
		return ;
		// main: 2 7 8 46 53 100
		//       ^    ^
		// pend: 7 11 2 27
	main.insert(main.begin(), pend[0]);
	// 2 1 4 3
	// Reminder!!: index 4 is not exist so binarySearch returns a wrong pos!
	std::vector<int> indexes = getOrderedIndexes();
	for (size_t i = 0; i < pend.size(); i++) {
		std::cout << "idx: " << indexes[i] << std::endl;
		if ((size_t)indexes[i] > pend.size() - 1)
			continue;
		int pos = binarySearch(pend[indexes[i]]);
		std::cout << "pos: " << pos << std::endl;
		main.insert(main.begin() + pos, pend[indexes[i]]);
	}
	pend.clear();
}

// // 0 1 1 3 5 11
// std::vector<int> getOrderedIndexes(std::vector<int> losers)  {
// 	// 3 2 5 4
// 	std::vector<int> indexes;
// 	for (size_t n = 3; n <= losers.size(); n++) {
// 		int jn = jacobOf(n);
// 		indexes.push_back(jn - 1);
// 		int prevJ = jacobOf(n - 1);
// 		for (int i = jn - 1; i > prevJ; i--)
// 			indexes.push_back(i - 1);
// 	}
// 	return indexes;
// }

void	buildPairs2(std::vector<std::pair<int, int> >& v, std::vector<int>& main) {
	for (size_t i = 0; i < main.size(); i++) {
		std::pair<int, int> p;
		p.first = main[i++];
		if (i < main.size() - 1) p.second = main[i];
		else p.second = -1;
		v.push_back(p);
	}
	main.clear();
}


void	VectorSort::sort(std::vector<std::pair<int, int> > v) {
	std::vector<int> main;
	std::vector<int> pend;

	buildPairs2(v, main);
}

VectorSort::~VectorSort(){}