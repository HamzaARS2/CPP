#ifndef RPN_HPP
# define RPN_HPP


#include <iostream>
#include <string>
#include <stack>
typedef std::string String;

//  "8 9 * 9 - 9 - 9 - 4 - 1 +"
//  "9 9 2 - -"
//  "1 2 * 2 / 2 * 2 4 - +"
//  "2 -2 +"
class RPN {
	private:
		String expression;
		int result;
		std::stack<int> stack;
		bool	isSolved;
		
		bool	isOperation(char c) const;
		void	runOperation(char operation);
	public:
		RPN();
		RPN(const RPN& copy);
		RPN(String expression);

		RPN&	operator=(const RPN& other);

		void	setExpression(const String& expression);
		void	solve();
		void	showResult() const;

		~RPN();
};

#endif