#include "LiteralValidation.hpp"

LiteralValidation::LiteralValidation() {
	
}

LiteralValidation::LiteralValidation(String literal) {
	this->literal = literal;
	this->length = literal.size();
	this->lastIndex = this->length - 1;
}

LiteralValidation::LiteralValidation(const LiteralValidation& copy) {
	*this = copy;
}

LiteralValidation&	LiteralValidation::operator=(const LiteralValidation& other) {
	if (this == &other)
		return *this;
	this->literal = other.literal;
	return *this;
}

bool	LiteralValidation::isInteger() {
	char *end;

	long nbr = std::strtol(literal.c_str(), &end, 10);
	if (*end != 0)
		return false;
	if (nbr > std::numeric_limits<int>::max() || nbr < std::numeric_limits<int>::min())
		return false;
	digitalForm = nbr;
	return true;
}

bool	LiteralValidation::isDouble() {
	char *e;

	double nbr = std::strtod(literal.c_str(), &e);
	if (*e != 0)
		return false;
	digitalForm = nbr;
	return true;
}

bool	LiteralValidation::isFloat() {
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


String	LiteralValidation::validate() {
	if (literal == "nan" || literal == "-inf" || literal == "+inf" ||
		literal == "nanf" || literal == "-inff" || literal == "+inff")
		return saveType(literal);
	if (length == 1 && std::isalpha(literal.at(0)))
		return saveType("c");
	if (isInteger())
		return saveType("i");
	if (isDouble())
		return saveType("d");
	if (isFloat())
		return saveType("f");
	return saveType("invalid");
}

String	LiteralValidation::castToChar() {
	if (this->type == "c")
		return literal;
	if (this->type == "i" || this->type == "d" || this->type == "f") {
		if (std::isprint((int)digitalForm))
			return ;
		else
			return "Not displayable";
	}
	return "Impossible";
}


String	LiteralValidation::saveType(String type) {
	this->type = type;
	return this->type;
}


LiteralValidation::~LiteralValidation() {

}