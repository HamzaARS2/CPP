#ifndef LITERAL_VALIDATION_HPP
# define LITERAL_VALIDATION_HPP


#include <iostream>
typedef std::string String;

class LiteralManager {
	private:
		String literal;
		double digitalForm;
		int	length;
		unsigned long lastIndex;
		String type;

		LiteralManager();
		String	saveType(String type);
	public:
		LiteralManager(const LiteralManager& copy);
		LiteralManager(String literal);

		LiteralManager& operator=(const LiteralManager& other);

		String	validate();
		bool	isDouble();
		bool	isFloat();
		bool	isInteger();

		void	printInfo(double digitalForm, char c, int i, float f, double d);
		void	printPseudoLiterals(String type);

		double	getDigitalForm() const;
		bool	isPseudoLiteral() const;
		
		~LiteralManager();
};

#endif

