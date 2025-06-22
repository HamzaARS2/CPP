#include "RPN.hpp"

RPN::RPN() {
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
	this->stack = other.stack;
	return *this;
}

void	RPN::setExpression(const String& expression) {
	this->expression = expression;
}

bool	RPN::isOperation(char c) const {
	return std::strchr("+-*/", c) != NULL;
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
		std::cout << "Pass the expression!" << std::endl;
		return ;
	}
	for (size_t i = 0; i < expression.length(); i++) {
		if (expression[i] == 32) continue;
		if (isOperation(expression[i]))
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