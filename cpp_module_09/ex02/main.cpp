#include "VectorSort.hpp"
#include <algorithm>

std::vector<int> getData(char **data) {
	std::vector<int> v;
	int i = 0;
	while (data[i])
		v.push_back(std::atoi(data[i++]));
	return v;
}

std::vector<std::pair<int, int> >	buildPairs(std::vector<int> v, int& unpaired) {
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

void	printPairs(std::vector<std::pair<int, int> > pairs, int unpaired) {
	std::cout << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
		std::cout << "[" << pairs[i].first << ", " << pairs[i].second << "]" << std::endl;
	std::cout << "unpaired: " << unpaired << std::endl;
}

void	printWinLosers(std::vector<int> winners, std::vector<int> losers, int unpaired) {
	std::cout << std::endl;
	std::cout << "winners: ";
	for (size_t i = 0; i < winners.size(); i++)
		std::cout << winners[i] << " ";
	std::cout << std::endl;
	std::cout << "losers: ";
	for (size_t i = 0; i < losers.size(); i++)
		std::cout << losers[i] << " ";
	std::cout << std::endl;
	std::cout << "unpaired: " << unpaired << std::endl;
}

void	comparePairs(std::vector<std::pair<int, int> > pairs, std::vector<int>& winners, std::vector<int>& losers) {
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

int	jacobOf(int n) {
	if (n == 0 || n == 1)
		return n;
	return jacobOf(n - 1) + (2 * jacobOf(n - 2));
}
// 0 1 1 3 5 11
std::vector<int> getOrderedIndexes(std::vector<int> losers)  {
	// 14 12 8
	// 0
	std::vector<int> indexes;
	for (size_t n = 2; n <= losers.size(); n++) {
		size_t jn = jacobOf(n);
		if (jn - 1 >= losers.size())
			break;
		indexes.push_back(jn - 1);
		int prevJ = jacobOf(n - 1);
		for (int i = jn - 1; i > prevJ ; i--)
			indexes.push_back(i - 1);
	}
	return indexes;
}

int	binarySearch(std::vector<int> v, int e) {
	// search 5
	// 2 6 8 9 12 14 17 21
	int l = 0, r = v.size() - 1;
	int m;
	while (l <= r) {
		int size = r - l;
		m = l + (size / 2);
		if (e > v[m]) 
			l = m + 1;
		else if (e < v[m]) 
			r = m - 1;
		else 
			return m;
	}
	return l;
}

void	binaryInsert(std::vector<int>& winners, std::vector<int>& losers, int unpaired) {
	if (losers.empty())
		return;
	// winners.insert(winners.begin(), losers[0]);
	std::vector<int> indexes = getOrderedIndexes(losers);
	std::cout << "indexes: ";
	for (size_t i = 0; i < indexes.size(); i++)
		std::cout << indexes[i] << " ";
	std::cout << std::endl;
	std::cout << "losers: ";
	for (size_t i = 0; i < losers.size(); i++)
		std::cout << losers[i] << " ";
	std::cout << std::endl;

	for (size_t i = 0; i < losers.size(); i++) {
		int idx = indexes.size() < 3 ? i : indexes[i];
		if (i < indexes.size())
			std::cout << "inserting: " << indexes[i] << std::endl;
		else
			std::cout << "inserting: out of bounds"  << std::endl;

		int pos = binarySearch(winners, losers[idx]);
		winners.insert(winners.begin() + pos, losers[idx]);
	}

	if (unpaired != -1) {
		int pos = binarySearch(winners, unpaired);
		winners.insert(winners.begin() + pos, unpaired);
	}
}

std::vector<int>	sort(std::vector<int> v) {
	int unpaired = -1;
	std::vector<int> winners;
	std::vector<int> losers;
	std::vector<std::pair<int, int> > pairs;
	if (v.size() <= 1)
		return v;
	// pairing
	pairs = buildPairs(v, unpaired);
	printPairs(pairs, unpaired);
	// comparing within pairs (creating winners and losers)
	comparePairs(pairs, winners, losers);
	printWinLosers(winners, losers, unpaired);
	winners = sort(winners);
	
	binaryInsert(winners, losers, unpaired);

	return winners;
}

bool isSorted(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i)
        if (vec[i] < vec[i - 1])
            return false;  
	return true;  
}

int	main(int ac, char **av) {
	if (ac <= 1)
		return 1;
	std::vector<int> data = getData(++av);
	// sort(data);
	std::vector<int> e;
	std::vector<int> sorted = sort(data);
	printWinLosers(sorted, e, -1);
	std:: cout << "is sorted: " << isSorted(sorted) << std::endl;
}