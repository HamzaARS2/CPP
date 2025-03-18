#include <iostream>

typedef std::string String;

int	main() {
	String greeting = "HI THIS IS BRAIN";
	String* stringPTR = &greeting;
	String& stringREF = greeting;

	// Printing memory addresses of above variables.
	std::cout << &greeting << std::endl
		<< &stringPTR << std::endl
		<< &stringREF << std::endl;

	// Printing values of above variables.
	std::cout << greeting << std::endl
		<< *stringPTR << std::endl
		<< stringREF << std::endl;
}