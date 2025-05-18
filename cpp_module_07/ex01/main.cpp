#include "iter.hpp"
#include <cmath>
#include "User.hpp"

void	toUpperCase(String& str) {
	for (size_t i = 0; i < str.length(); i++)
		str.at(i) = std::toupper(str.at(i));
}

void roundInPlace(float& x) {
    x = roundf(x);
}

void	squareInt(int& n) {
	n *= n;
}



int	main() {
	// Empty array of strings
	String strings2[0];
	iter(strings2, 0 ,toUpperCase);
	printAny(strings2, 0);

	String strings[] = {"Fennec", "Octane", "Merc"};
	iter(strings,3 ,toUpperCase);
	printAny(strings, 3);

	// Array of floats
	float floats[] = {32.99f, 13.37f, 1.5f, 7338.6f};
	iter(floats, 4, roundInPlace);
	printAny(floats, 4);
	
	// Array of ints
	int numbers[] = {1, 2, 3, 4, 5};
	iter<int, void (int&)>(numbers, 5, squareInt);
	printAny(numbers, 5);
	User users[] = {User("Klock", 10), User("Lorem", 19), User("Merol", 7)};

}