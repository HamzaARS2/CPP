#include "MutantStack.hpp"

int	main() {
	MutantStack<int> mStack;
	mStack.push(1);
	mStack.push(2);
	mStack.push(3);
	MutantStack<int> mStack2 = mStack;
	mStack2.push(4);
	MutantStack<int>::
	std::cout << mStack.top() << std::endl;

	std::cout << mStack2.top() << std::endl;
}