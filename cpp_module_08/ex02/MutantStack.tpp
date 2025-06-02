#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
	
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& copy) {
	*this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack() {

}