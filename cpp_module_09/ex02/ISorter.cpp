#include "Sorter.hpp"
#include <deque>
int	ISorter::jacobOf(int n) {
	if (n == 0 || n == 1)
		return n;
	return jacobOf(n - 1) + (2 * jacobOf(n - 2));
}

int	ISorter::binarySearch(std::vector<int> v, int e) {
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
