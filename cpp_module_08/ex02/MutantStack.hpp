#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
#include <vector>
typedef std::string String;


template <typename T>
class MutantStack: public std::stack<T> {
	public:
		class iterator;
		MutantStack();
		MutantStack(const MutantStack<T>& copy);

		MutantStack<T>&	operator=(const MutantStack<T>& other);

		iterator	begin();
		iterator	end();
		~MutantStack();
};



#include "iterator.tpp"

#include "MutantStack.tpp"

#endif