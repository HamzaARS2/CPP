#ifndef LITERAL_VALIDATION_HPP
# define LITERAL_VALIDATION_HPP


#include <iostream>
typedef std::string String;

class LiteralValidation {
	private:
		String literal;
		double digitalForm;
		int	length;
		unsigned long lastIndex;
		String type;

		LiteralValidation();
		String	saveType(String type);
	public:
		LiteralValidation(const LiteralValidation& copy);
		LiteralValidation(String literal);

		LiteralValidation& operator=(const LiteralValidation& other);

		String	validate();
		bool	isDouble();
		bool	isFloat();
		bool	isInteger();

		double	getDigitalForm() const;
		bool	isPseudoLiteral() const;
		String	castToChar();
		String	castToInt();
		String	castToDouble();
		String	castToFloat();
		
		~LiteralValidation();
};

#endif

