#include "Array.hpp"
#include "Student.hpp"


int	main() {
	// Empty array of ints
	Array<int> empty;
	std::cout << empty << std::endl;

	// Array of ints
	Array<int> ints(10);
	for (size_t i = 0; i < ints.size(); i++)
		ints[i] = i + 1;
	std::cout << ints << std::endl;	

	// Array of strings
	Array<String> games(3);
	games[0] = "Rocket league";
	games[1] = "Battlefield 2042";
	games[2] = "Counter strike 1.6";
	std::cout << games << std::endl;

	// Copy of games array
	std::cout << "Coping games to list2Games array...\n" << std::endl;
	Array<String> list2Games = games;
	list2Games[0] = "Sea of Theives";
	list2Games[1] = "Little Nightmares";
	list2Games[2] = "Half Life";

	std::cout << "List2Games array:" << std::endl;
	std::cout << list2Games << std::endl;
	std::cout << "===============================================" << std::endl;
	std::cout << "games array:" << std::endl;
	std::cout << games << std::endl;

	std::cout << "============ Students =============" << std::endl;

	// Array of student objects
	Array<Student> students(3);
	students[0] = Student("Fennec", 16, true);
	students[1] = Student("Octane", 13, true);
	students[2] = Student("Merc", 9, false);
	try {
		students[3] = Student("Dominus", 11, true);
	} catch (Array<Student>::ArrayOutOfBoundsException& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << students << std::endl;
} 