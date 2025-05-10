#include "ScalarConverter.hpp"
#include <limits.h>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

void	ScalarConverter::convert(String literal) {
	LiteralValidation lv(literal);
	// char c;
	
	std::cout << "Type: " + lv.validate() << std::endl;
	std::cout << "char: " + lv.castToChar() << std::endl;
}


void	printInfo(String c, String i, String f, String d) {
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}

ScalarConverter::~ScalarConverter() {}