#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <deque>
typedef std::string String;


template <typename T>
class MutantStack: public std::stack<T> {
	public:
		class iterator;
		MutantStack();
		MutantStack(const MutantStack& copy);
		iterator	begin();
		iterator	end();
		~MutantStack();
};

template <typename T>
class MutantStack<T>::iterator {
	public:
		T* ptr;
		iterator(T* ptr);

};

#include "iterator.tpp"

#include "MutantStack.tpp"

#endif