#include "MutantStack.hpp"

int	main() {
	MutantStack<int> mStack;
	mStack.push(1);
	mStack.push(2);
	mStack.push(3);
	MutantStack<int> mStack2 = mStack;
	mStack2.push(4);
	MutantStack<int>::iterator it = mStack.begin();
	(void)it;
	std::cout << *it.ptr << std::endl;

	// std::cout << mStack2.top() << std::endl;
}