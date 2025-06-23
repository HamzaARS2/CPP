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


void	RPN::runOperation(char operation) {
	int o2 = stack.top();
	stack.pop();
	int o1 = stack.top();
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
			stack.push(o1 / o2);
	}
}

void	RPN::solve() {
	if (expression.empty()) {
		std::cout << "No expression set!" << std::endl;
		return ;
	}
	for (size_t i = 0; i < expression.length(); i++) {
		if (expression[i] == 32) continue;
		if (RPNValidator::isOperation(expression[i]))
			runOperation(expression[i]);
		else
			stack.push(expression[i] - 48);
	}
	result = stack.top();
	isSolved = true;
	stack.pop();
}

void	RPN::showResult() const {
	if (isSolved)
		std::cout << result << std::endl;
	else
		std::cout << "Solve the expression!" << std::endl;
}

RPN::~RPN() {

}