#include "MutantStack.hpp"

template <typename T>
void	showStackFromTop(MutantStack<T> stack) {
	typename MutantStack<T>::const_reverse_iterator it;
	for (it = stack.rbegin(); it != stack.rend(); it++) {
		std::cout << " [" << *it << "] ";
	}
	std::cout << std::endl;
}

template <typename T>
void	showStackFromBot(MutantStack<T> stack) {
	typename MutantStack<T>::const_iterator it;

	for (it = stack.begin(); it != stack.end(); it++)
		std::cout << " [" << *it << "] ";
	std::cout << std::endl;
}


int main() {
    MutantStack<int> mstack;

    std::cout << "=== Basic Stack Operations ===" << std::endl;
    mstack.push(42);
    mstack.push(17);
    mstack.push(3);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Top after pop: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;

    std::cout << "\n=== Iterator (Bottom to Top) ===" << std::endl;
    mstack.push(5);
    mstack.push(99);
    showStackFromBot(mstack);

    std::cout << "\n=== Reverse Iterator (Top to Bottom) ===" << std::endl;
    showStackFromTop(mstack);

    std::cout << "\n=== Copy Constructor & Assignment ===" << std::endl;
    MutantStack<int> mstack2(mstack);
    showStackFromTop(mstack2);
    MutantStack<int> mstack3;
    mstack3 = mstack2;
    showStackFromBot(mstack3);

    std::cout << "\n=== Compatibility with std::stack ===" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "std::stack top after copy: " << s.top() << std::endl;

    std::cout << "\n=== Empty Stack ===" << std::endl;
    MutantStack<int> emptyStack;
    showStackFromBot(emptyStack);
    showStackFromTop(emptyStack);

    return 0;
}

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
	
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }