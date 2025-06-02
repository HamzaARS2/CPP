#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stack>
typedef std::string String;

template <typename T>
class MutantStack: public std::stack<T> {
	private:
	public:
		static String iterator;
		MutantStack();
		MutantStack(const MutantStack& copy);

		~MutantStack();
};

#include "MutantStack.tpp"

#endif