#include "VectorSort.hpp"

VectorSort::VectorSort() {}

VectorSort::VectorSort(const VectorSort& copy) {
	*this = copy;
}

VectorSort&	VectorSort::operator=(const VectorSort& other) {
	if (this == &other)
		return *this;
	return *this;
}

std::vector<std::pair<int, int> >	VectorSort::buildPairs(std::vector<int> v, int& unpaired) {
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < v.size(); i++) {
		std::pair<int, int> p;
		if (i + 1 >= v.size()) {
			unpaired = v[i];
			break;
		}
		p.first = v[i++];
		p.second = v[i];
		pairs.push_back(p);
	}
	return pairs;
}

void	VectorSort::comparePairs(std::vector<std::pair<int, int> > pairs, std::vector<int>& winners, std::vector<int>& losers) {
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i].first >= pairs[i].second) {
			winners.push_back(pairs[i].first);
			losers.push_back(pairs[i].second);
		} else {
			losers.push_back(pairs[i].first);
			winners.push_back(pairs[i].second);
		}
	}
}

int	VectorSort::jacobOf(int n) {
	if (n == 0 || n == 1)
		return n;
	return jacobOf(n - 1) + (2 * jacobOf(n - 2));
}

std::vector<int> VectorSort::getOrderedIndexes(std::vector<int> losers)  {
	std::vector<int> indexes;
	std::vector<bool> used(losers.size(), false);
	size_t n = 2;
	while (true) {
		size_t jn = jacobOf(n); // 1, 3, 5, 11
		size_t idx = jn - 1; // 0, 2, 4, 10
		if (idx >= losers.size())
			break;
		indexes.push_back(idx);
		used[idx] = true;
		n++;
	}
	for (size_t i = 0; i < losers.size(); i++) {
		if (!used[i])
			indexes.push_back(i);
	}
	return indexes;
}

int	VectorSort::binarySearch(std::vector<int> v, int e) {
	// search 5
	// 2 6 8 9 12 14 17 21
	int l = 0, r = v.size() - 1;
	int m;
	static int c = 0;
	while (l <= r) {
		int size = r - l;
		m = l + (size / 2);
		c++;
		if (e > v[m]) 
			l = m + 1;
		else if (e < v[m])
			r = m - 1;
		else
			return m;
	}
	std::cout << "comps: " << c << std::endl;
	return l;
}

void	VectorSort::binaryInsert(std::vector<int>& winners, std::vector<int>& losers, int unpaired) {
	if (losers.empty())
		return;
	std::vector<int> indexes = getOrderedIndexes(losers);
	for (size_t i = 0; i < losers.size(); i++) {
		int idx = indexes[i];
		int pos = binarySearch(winners, losers[idx]);
		winners.insert(winners.begin() + pos, losers[idx]);
	}
	if (unpaired != -1) {
		int pos = binarySearch(winners, unpaired);
		winners.insert(winners.begin() + pos, unpaired);
	}
}

std::vector<int>	VectorSort::sort(std::vector<int> v) {
	int unpaired = -1;
	std::vector<int> winners;
	std::vector<int> losers;
	std::vector<std::pair<int, int> > pairs;
	if (v.size() <= 1)
		return v;
	// pairing
	pairs = buildPairs(v, unpaired);
	// comparing within pairs (creating winners and losers)
	comparePairs(pairs, winners, losers);
	// calling sort recursively to pair the next level winners
	winners = sort(winners);
	//inserting losers into winners of the current recursivity level
	binaryInsert(winners, losers, unpaired);

	return winners;
}


VectorSort::~VectorSort(){}