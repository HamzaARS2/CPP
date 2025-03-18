
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"



void update(Weapon* weapon) {
	weapon->setType("warbow");
}


int	main() {
	Weapon weapon = Weapon("whispering bow");
	std::cout << weapon.getType() << std::endl;
	update(&weapon);
	std::cout << weapon.getType() << std::endl;
}























// int	main() {
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 		Weapon bobWeapon = bob.getWeapon();
// 		std::cout << &club << " | " << &bobWeapon
// 			<< std::endl;
// 	}
// 	// {
// 	// 	Weapon club = Weapon("crude spiked club");
// 	// 	HumanB jim("Jim");
// 	// 	jim.setWeapon(club);
// 	// 	jim.attack();
// 	// 	club.setType("some other type of club");
// 	// 	jim.attack();
// 	// }
// }