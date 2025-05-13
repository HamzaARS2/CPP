#include "ScalarConverter.hpp"
#include <limits.h>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

void	ScalarConverter::convert(String literal) {
	LiteralManager lm(literal);
	String type = lm.validate();
	if (type == "invalid") {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: Impossible" << std::endl;
		std::cout << "double: Impossible" << std::endl;
	} else if (lm.isPseudoLiteral())
		lm.printPseudoLiterals(type);
	else
		lm.printInfo(lm.getDigitalForm(),
			static_cast<char>(lm.getDigitalForm()),
			static_cast<int>(lm.getDigitalForm()),
			static_cast<float>(lm.getDigitalForm()),
			static_cast<double>(lm.getDigitalForm())
		);
}



ScalarConverter::~ScalarConverter() {}