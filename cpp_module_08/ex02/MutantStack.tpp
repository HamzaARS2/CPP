#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
	
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) {
	*this = copy;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return iterator(&this->c[0]);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return iterator(&this->c[2]);
}

template <typename T>
MutantStack<T>::~MutantStack() {

}