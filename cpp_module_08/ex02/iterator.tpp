#include "MutantStack.hpp"

template <typename T>
class MutantStack<T>::iterator {
	private:
    	T* ptr;

	public:
		iterator(T* ptr): ptr(ptr) {}

        // Dereference
        T&  operator*() const {
            return *ptr;
        }

        // Pre-increment
        MutantStack<T>::iterator  operator++() {
            ++ptr;
            return *this;
        }

        // Post-increment
        MutantStack<T>::iterator  operator++(int) {
            MutantStack<T>::iterator it = *this;
            ++ptr;
            return it;
        }

        // Pre-decrement
        MutantStack<T>::iterator    operator--() {
            --ptr;
            return *this;
        }

        // Post-decrement
        MutantStack<T>::iterator    operator--(int) {
            MutantStack<T>::iterator it = *this;
            --ptr;
            return *this;
        }

        // Equality
        bool    operator==(const MutantStack<T>::iterator& other) {
            return this->ptr == other.ptr;
        }

        // Non-equality
        bool    operator!=(const MutantStack<T>::iterator& other) {
            return this->ptr != other.ptr;
        }
};