#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::iterator::iterator(T* ptr): ptr(ptr) {}