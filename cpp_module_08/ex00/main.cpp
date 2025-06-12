#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include "easyfind.hpp"


int	main() {

	std::cout << "========== Vector Container ===========" << std::endl;
	std::vector<int> vector;
	vector.push_back(1);
	vector.push_back(0);
	vector.push_back(4);
	std::vector<int>::iterator vIter = easyfind(vector, 4);
	std::cout << *vIter << std::endl;
	std::cout << "!!!!! Value not found case !!!!!" << std::endl;
	try {
		easyfind(vector, 5);
	} catch (std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "========== List Container ===========" << std::endl;
	std::list<int> list;
	list.push_back(321);
	list.push_back(43);
	list.push_back(13);
	std::list<int>::iterator lstIter = easyfind(list, 43);
	std::cout << *lstIter << std::endl;

	std::cout << "========== Deque Container ===========" << std::endl;
	std::deque<int> deque;
	deque.push_front(21);
	deque.push_back(83);
	deque.push_front(435);
	std::deque<int>::iterator dqIter = easyfind(deque, 21);
	std::cout << *dqIter << std::endl;
}