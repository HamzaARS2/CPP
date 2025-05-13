#include "LiteralManager.hpp"
#include <sstream>
#include <iomanip>

LiteralManager::LiteralManager() {
	
}

LiteralManager::LiteralManager(String literal) {
	this->literal = literal;
	this->length = literal.size();
	this->lastIndex = this->length - 1;
}

LiteralManager::LiteralManager(const LiteralManager& copy) {
	*this = copy;
}

LiteralManager&	LiteralManager::operator=(const LiteralManager& other) {
	if (this == &other)
		return *this;
	this->literal = other.literal;
	return *this;
}

bool	LiteralManager::isInteger() {
	char *end;

	long nbr = std::strtol(literal.c_str(), &end, 10);
	if (*end != 0)
		return false;
	if (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min())
		return false;
	digitalForm = nbr;
	return true;
}

bool	LiteralManager::isDouble() {
	char *e;

	double nbr = std::strtod(literal.c_str(), &e);
	if (*e != 0)
		return false;
	digitalForm = nbr;
	return true;
}

bool	LiteralManager::isFloat() {
	char *e;

	double nbr = std::strtod(literal.c_str(), &e);
	if (*e != 0 && *e != 'f')
		return false;
	if (std::count(literal.begin(), literal.end(), 'f') != 1)
		return false;
	size_t fIndex = literal.find('f');
	if (fIndex == std::string::npos || fIndex != lastIndex)
		return false;
	digitalForm = nbr;
	return true;
}


String	LiteralManager::validate() {
	if (literal == "nan" || literal == "-inf" || literal == "+inf" ||
		literal == "nanf" || literal == "-inff" || literal == "+inff")
		return saveType(literal);
	if (literal.size() == 1 && !std::isdigit(literal.at(0))) {
		this->digitalForm = static_cast<double>(literal.at(0));
		return saveType("c");
	}
	if (isInteger())
		return saveType("i");
	if (isDouble())
		return saveType("d");
	if (isFloat())
		return saveType("f");
	return saveType("invalid");
}

void	LiteralManager::printInfo(double digitalForm, char c, int i, float f, double d) {
	if (std::isprint(c))
		std::cout << "char: '" << c << "'"<< std::endl;
	else if (digitalForm > std::numeric_limits<char>::max() || digitalForm < std::numeric_limits<char>::min())
		std::cout << "char: Impossible"<< std::endl;
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

void	LiteralManager::printPseudoLiterals(String type) {
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


bool	LiteralManager::isPseudoLiteral() const {
	return literal == "nan" || literal == "-inf" || literal == "+inf" ||
		literal == "nanf" || literal == "-inff" || literal == "+inff";
}

double	LiteralManager::getDigitalForm() const {
	return this->digitalForm;
}

String	LiteralManager::saveType(String type) {
	this->type = type;
	return this->type;
}


LiteralManager::~LiteralManager() {

}