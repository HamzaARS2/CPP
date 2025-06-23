#ifndef RPN_VALIDATOR_HPP
# define RPN_VALIDATOR_HPP


#include <iostream>
typedef std::string String;
//  "8 9 * 9 5 - 9 - 9 - 4 - 1 +"
//  "- 7 2 +"
class RPNValidator {
	private:
		RPNValidator();

		static bool	isDigit(char c);
		static bool	isValidSequence(const String& expression);
		static bool	isValidChars(const String& expression);
		static bool	isBalanced(const String& expression);
	public:
		static bool	isOperation(char c);
		static bool	validate(const String& expression);
};


#endif