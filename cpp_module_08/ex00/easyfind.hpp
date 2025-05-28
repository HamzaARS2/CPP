#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <iostream>
#include <algorithm>
typedef std::string String;


template <typename T>
typename T::iterator	easyfind(T& container, int toFind);

#include "easyfind.tpp"

#endif