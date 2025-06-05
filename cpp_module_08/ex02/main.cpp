#include "MutantStack.hpp"
#include <list>

// int	main() {
// 	MutantStack<int> mStack;
// 	mStack.push(1);
// 	mStack.push(2);
// 	mStack.push(3);
// 	MutantStack<int> mStack2 = mStack;
// 	mStack2.push(4);
// 	MutantStack<int>::iterator it = mStack.begin();
// 	for (;it != mStack.end(); ++it) {
// 		std::cout << *it << std::endl;
// 	}
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}