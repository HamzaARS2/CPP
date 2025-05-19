#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
typedef std::string String;

template <typename T>
class Array {
	private:
		T* array;
		size_t length;

	public:
		class ArrayOutOfBoundsException: public std::exception {
			public:
				const char* what() const throw();
		};
		Array();
		Array(size_t n);
		Array(const Array& copy);

		Array&	operator=(const Array& other);
		T&	operator[](size_t index);
		const T&	operator[](size_t index) const;

		size_t	size() const;
		~Array();
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& array);

#include "Array.tpp"

#endif