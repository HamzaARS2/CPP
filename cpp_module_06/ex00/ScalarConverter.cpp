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

void	printInfo(double digitalForm, char c, int i, float f, double d) {
	if (std::isprint(c))
		std::cout << "char: '" << c << "'"<< std::endl;
	else
		std::cout << "char: Not displayable"<< std::endl;
	if (digitalForm > std::numeric_limits<int>::max() || digitalForm < std::numeric_limits<int>::min())
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	if (digitalForm > std::numeric_limits<int>::max())
		std::cout << "float: +inff" << std::endl;
	else if (digitalForm < std::numeric_limits<int>::min())
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	printPseudoLiterals(String type) {
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	if (type == "nanf" || type == "-inff" || type == "+inff")
		std::cout << "float: " + type << std::endl;
	else
		std::cout << "float: " + type + "f" << std::endl;
	if (type == "nan" || type == "-inf" || type == "+inf")
		std::cout << "double: " + type << std::endl;
	else
		std::cout << "double: " + type.erase(type.size() - 1) << std::endl;

}

void	ScalarConverter::convert(String literal) {
	LiteralValidation lv(literal);
	String type = lv.validate();
	if (type == "invalid") {
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: Impossible" << std::endl;
		std::cout << "double: Impossible" << std::endl;
	} else if (lv.isPseudoLiteral())
		printPseudoLiterals(type);
	else
		printInfo(lv.getDigitalForm(),
			static_cast<char>(lv.getDigitalForm()),
			static_cast<int>(lv.getDigitalForm()),
			static_cast<float>(lv.getDigitalForm()),
			static_cast<double>(lv.getDigitalForm())
		);
}



ScalarConverter::~ScalarConverter() {}