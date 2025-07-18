#include "RPNValidator.hpp"
#include <algorithm>
#include <stack>

RPNValidator::RPNValidator() {}

bool	RPNValidator::isOperation(char c) {
	return std::strchr("+-*/", c) != NULL;
}

bool	RPNValidator::isDigit(char c) {
	return std::isdigit(c);
}

bool	RPNValidator::isValidChars(const String& expression) {
	for (size_t i = 0; i < expression.length(); i++) {
		if ((i == 0 || i == 2) && !isDigit(expression[i]))
			return false;
		if (i % 2 == 0 && (!std::isdigit(expression[i]) && !isOperation(expression[i])))
			return false;
		if (i % 2 == 1 && expression[i] != 32)
			return false;
	}
	return true;
}

bool	RPNValidator::isBalanced(const String& expression) {
	int digitsCount = count_if(expression.begin(), expression.end(), isDigit);
	int operationsCount = count_if(expression.begin(), expression.end(), isOperation);
	return (digitsCount == operationsCount + 1) && (digitsCount > 1);
}

bool	RPNValidator::validate(const String& expression) {
	if (expression.empty()) {
		std::cerr << "expression not set" << std::endl;
		return false;
	}
	if (!isValidChars(expression)) {
		std::cerr << "invalid expression" << std::endl;
		return false;
	}
	if (!isBalanced(expression)) {
		std::cerr << "expression not balanced" << std::endl;
		return false;
	}
	return true;
}

