#ifndef WHATEVER_HPP
# define WHATEVER_HPP


#include <iostream>
typedef std::string String;

template <typename T>
void swap(T& a1, T& a2) {
	T temp = a1;
	a1 = a2;
	a2 = temp;
}

template <typename I>
I min(I n1, I n2) {
	return (n1 > n2) ? n2 : n1;
}

template <typename X>
X max(X n1, X n2) {
	return (n1 > n2) ? n1 : n2;
}


#endif