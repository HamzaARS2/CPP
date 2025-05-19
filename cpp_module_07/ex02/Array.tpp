#include "Array.hpp"

template <typename T>
const char*	Array<T>::ArrayOutOfBoundsException::what() const throw() {
	return "Array index out of bounds!";
}

template <typename T>
Array<T>::Array() {
	this->array = NULL;
	this->length = 0;
}

template <typename T>
Array<T>::Array(size_t n) {
	this->array = new T[n];
	this->length = n;
}

template <typename T>
Array<T>::Array(const Array& copy) {
	array = new T[copy.size()];
	length = copy.size();
	for (size_t i = 0; i < copy.size(); i++)
		this->array[i] = copy.array[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& other) {
	if (this == &other)
		return *this;
	delete[] array;
	array = new T[other.size()];
	length = other.size();
	for (size_t i = 0; i < other.size(); i++)
		array[i] = other.array[i];
	return *this;
}

template <typename T>
T&	Array<T>::operator[](size_t index) {
	if (index >= length)
		throw ArrayOutOfBoundsException();
	return array[index];
}


template <typename T>
const T&	Array<T>::operator[](size_t index) const {
	if (index >= length)
		throw ArrayOutOfBoundsException();
	return array[index];
}


template <typename T>
size_t	Array<T>::size() const {
	return length;
}

template <typename T>
Array<T>::~Array() {
	delete[] array;
}

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& array) {
	out << "[";
	for (size_t i = 0; i < array.size(); i++) {
		out << array[i];
		if (i != array.size() - 1)
			out << ", ";
	}
	out << "]";
	return out;
}