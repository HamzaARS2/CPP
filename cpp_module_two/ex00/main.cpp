#include "Zombie.hpp"


int	main() {
	Zombie* zombie = newZombie("Hamza");
	zombie->announce();
	Zombie stackZombie("StackHamza");

	randomChump("RandomChumpZombie");
	delete zombie;
}