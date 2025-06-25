#ifndef RPN_HPP
# define RPN_HPP


#include <iostream>
#include <string>
#include <stack>
typedef std::string String;

class RPN {
	private:
		String expression;
		int result;
		std::stack<int> stack;
		bool	isSolved;
		bool	isValid;

		bool	runOperation(char operation);
	public:
		RPN();
		RPN(const RPN& copy);
		RPN(String expression);

		RPN&	operator=(const RPN& other);

		void	setExpression(const String& expression);
		bool	solve();
		void	showResult() const;

		~RPN();
};

#endif