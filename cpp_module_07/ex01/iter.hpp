#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
typedef std::string String;

template <typename A, typename F>
void	iter(A* array, size_t length, F func) {
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void	printAny(T* any, size_t length) {
	for (size_t i = 0; i < length; i++)
		std::cout << any[i] << " ";
	std::cout << std::endl;
}

#endif