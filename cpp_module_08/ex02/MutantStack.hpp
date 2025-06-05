#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

typedef std::string String;


template <typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		
	public:
		MutantStack();
		MutantStack(const MutantStack<T>& copy);

		MutantStack<T>&	operator=(const MutantStack<T>& other);
		
		iterator	begin();
		iterator	end();
		const_iterator	begin() const;
		const_iterator	end() const;
		
		reverse_iterator	rbegin();
		reverse_iterator	rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;

		~MutantStack();
};


#include "MutantStack.tpp"

#endif