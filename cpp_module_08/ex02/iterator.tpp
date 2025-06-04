#include "MutantStack.hpp"
#include <vector>
template <typename T>
class MutantStack<T>::iterator {
	public:
		T* ptr;
		iterator(T* ptr): ptr(ptr) {}

        // operators
	public:
        // Dereference
        T&  operator*() {
            return *ptr;
        }
        // Pre-increment
        T&  operator++() {
            ++ptr;
            return *this;
        }

        // Post-increment
        T&  operator++(T) {
            MutantStack<T>::iterator it = *this;
            ++ptr;
            return it;
        }
		

};