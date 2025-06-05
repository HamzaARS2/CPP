#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy) {
	*this = copy;
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& other) {
	std::cout << "copy assignment" << std::endl;
	if (this == &other)
		return *this;
	std::stack<T, std::vector<T> >::operator=(other);
	return *this;
}


template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return iterator(&this->c[0]);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return iterator(&this->c[this->size()]);
}

template <typename T>
MutantStack<T>::~MutantStack() {

}