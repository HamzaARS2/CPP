#include "Zombie.hpp"


int	main() {
	Zombie* zombie = newZombie("Hamza");
	zombie->announce();

	randomChump("RandomChumpZombie");
	delete zombie;
}