#include "RPN.hpp"
#include "RPNValidator.hpp"

RPN::RPN() {
	this->isSolved = false;
	this->isValid = false;
}

RPN::RPN(const RPN& copy) {
	*this = copy;
}

RPN::RPN(String expression) {
	this->expression = expression;
}

RPN&	RPN::operator=(const RPN& other) {
	if (this == &other)
		return *this;
	this->expression = other.expression;
	this->result = other.result;
	this->isSolved = other.isSolved;
	this->isValid = other.isValid;
	this->stack = other.stack;
	return *this;
}

void	RPN::setExpression(const String& expression) {
	this->expression = expression;
}


bool	RPN::runOperation(char operation) {
	if (stack.size() <= 1)
		return false;
	double o2 = stack.top();
	stack.pop();
	double o1 = stack.top();
	stack.pop();

	switch(operation) {
		case '+':
			stack.push(o1 + o2);
			break;
		case '-':
			stack.push(o1 - o2);
			break;
		case '*':
			stack.push(o1 * o2);
			break;
		case '/':
			if (o2 != 0) stack.push(o1 / o2);
			else return false;
	}
	return true;
}

bool	RPN::solve() {
	if (expression.empty()) {
		std::cout << "No expression set!" << std::endl;
		return false;
	}
	for (size_t i = 0; i < expression.length(); i++) {
		if (expression[i] == 32) continue;
		if (RPNValidator::isOperation(expression[i])) {
			if (!runOperation(expression[i])) {
				std::cerr << "invalid expression" << std::endl;
				return false;
			}
		}
		else
			stack.push(expression[i] - 48);
	}
	if (stack.size() != 1) {
		std::cerr << "invalid expression" << std::endl;
		return false;
	}
	result = stack.top();
	isSolved = true;
	stack.pop();
	return true;
}

void	RPN::showResult() const {
	if (isSolved)
		std::cout << result << std::endl;
}

RPN::~RPN() {

}