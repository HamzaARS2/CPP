#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include "LiteralManager.hpp"

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);

		ScalarConverter&	operator=(const ScalarConverter& other);

		~ScalarConverter();
	public:

		static void	convert(String literal);
};


#endif
