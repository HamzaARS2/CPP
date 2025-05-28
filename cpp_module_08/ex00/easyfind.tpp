#include "easyfind.hpp"


template <typename T>
typename T::iterator easyfind(T& container, int toFind) {
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::runtime_error("The value cannot be found");
	return it;
}